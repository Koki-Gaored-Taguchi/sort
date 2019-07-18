#include <stdio.h>

// 素数
#define N 2999

int A[N];


// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int quick_select_o(int A[], int n, int k){
    int i, j, pivot;
    
    // 真ん中の要素をピボットとする
    pivot = A[n/2];
    A[n/2] = A[0];
    A[0] = pivot;
    for(i = j = 1; i < n; i++){
        if(A[i] <= pivot){
            swap(A+i, A+j);
            j++;
        }
    }
    
    if(j == k+1) return pivot;
    else if(j < k+1) return quick_select_o(A+j, n-j, k-j);
    else return quick_select_o(A+1, j-1, k);
}

int quick_select(int A[], int n, int k){
  int i, j, pivot;
    int B[N];
    if(n<=5){return quick_select_o(A,n,k);}

    for(i=0;i<=((n-1)/5);i++){
        if(5*i+5<=n){
 

            B[i]=quick_select_o(A+5*i,5,2);
                    }
        else{
            B[i]=quick_select_o(A+5*i,n-5*i,((n-5*i)/2));
        }
        
    }
    
    int m=quick_select(B,((n-1)/5)+1,(((n/5)+1)/2));
    pivot=m;
    int h=0;//pivotがA[]に現れたら、その後は常に1で、1の時は要素を一つずつずらしている。
    for(i=0;i<n;i++){//A[]からpivotを抜く
        if(A[i]==pivot){h=1;}
        if(h==1){
            if(i==n-1){A[i]=pivot;}
            else{A[i]=A[i+1];}
            
        }
    }
  for(i = j = 0; i < n-1; i++){//pivotを抜いたので要素がn-1となった
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

    
  if(j == k) return pivot;
  else if(j < k) return quick_select(A+j, n-1-j, k-j-1);
  else return quick_select(A, j, k);
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
    int B[N];
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }

}
