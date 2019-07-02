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
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
    int i,j,l,pivot;
    
    pivot=A[n/2];
    A[n/2]=A[0];
    A[0]=pivot;
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
    int s;
    for(s=0;s<l;s++){
        swap(A+s,A+j-1-s);
    }

        if(n<=0){return;}
        else{return quick_sort(A+0,j-l),quick_sort(A+j,n-j);}
        
    }
    

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
