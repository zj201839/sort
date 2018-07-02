#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];
int B[N];  //各中央値を入れる配列

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/

int select_short(int C[], int n, int k){
    //長さnが５以下の配列のk+1番目に小さい要素を求める
    int i;
    for(i = 0 ; i < n ; i++){
        if(C[0]>C[i]){
            int s = C[i];
            C[i] = C[0];
            C[0] = s;
        }
    }       //最小値ーそれ以外
    if(k==0){return C[0];}
    return select_short(C+1,n-1,k-1);
    
}



int quick_select(int A[], int n, int k){
  int i, j, pivot;
  if(n<=5){return select_short(A,n,k);}
  
  else{
  
  int g;
  for(g = 0 ; g < (n+4)/5-1 ; g++){
    B[g] = select_short(A+5*g,5,2);
  }
  B[g] = select_short(A+5*g,n-5*g,(n-5*g)/2);
  pivot = quick_select(B,g+1,(g+1)/2);//
  
  //pivotと等しい要素一つを先頭と入れ替える
  int t, flag;
  flag = 1;
  for(t = 0 ; t < n ; t++){
    if(A[t]==pivot && flag){
        int sw = A[t];
        A[t] = A[0];
        A[0] = sw;
        flag = 0;
    }
  }
  
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      int z = A[j];
      A[j] = A[i];
      A[i] = z;
      j++;
    }
  }
  

  
  if(j == k+1) return pivot;
  else if(j < k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+1, j-1, k);
  }
}



int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}










