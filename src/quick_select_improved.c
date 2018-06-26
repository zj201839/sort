#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
    int l ,r ,i ,pivot;
    if(n==1)return A[0];
    pivot = A[0];
    r = n-1;
    for(l=i=1 ; i<n ; i++){   //
     if(A[i]<pivot){
       int z = A[l];
       A[l] = A[i];
       A[i] = z;  
       l++; 
     }
     }
     for(i=n-1 ; i>0 ; i--){
      if(A[i]>pivot){
        int w = A[r];
        A[r] = A[i];
        A[i] = w;
        r--;
     }
     }
     
     int q = A[0];
     A[0] = A[l-1];
     A[l-1] = q;
 
     if(k<l-1) return quick_select(A,l-1,k);
     else if(l-1<=k && k<=r) return pivot;
     else return quick_select(A+r+1,n-r-1,k-r-1);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
