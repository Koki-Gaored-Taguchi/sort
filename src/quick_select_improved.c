#include <stdio.h>

// 素数
#define N 2999

int A[N];
int B[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int i, j, l, pivot;

// 真ん中の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;
  for(i = j = l = 1; i < n; i++){
    if(A[i] < pivot){
      swap(A+i, A+j);
      j++;
    }
    else if(A[i]==pivot){
        if(l!=j){
            swap(A+i,A+l);
            swap(A+i,A+j);
            j++;
            l++;
        }
        else{
            swap(A+i,A+l);
            j++;
            l++;
        }
    }
  }

  if(j == k+1 || ((k+1<j) && (j-l<=k))) return pivot;
  else if(j< k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+l, j-1, k);
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
    
  B[0] = 0;
  for(i=1;i<N;i++){
      B[i] = (long long int) B[i-1];
      
  }


// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
    for(i=0;i<N;i++){
        if(quick_select(B, N, i) != 0) printf("ERROR %d %d\n", i, quick_select(B, N, i));

    }
}
