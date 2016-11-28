#include<iostream>
#include<cstdlib>
#include<limits.h>
using namespace std;

int random(int min,int max){
  return rand()%(max-min+1)+min;
}

int min(int a,int b){
  return a<b?a:b;
}
void randerizar(int **M,int r,int c){
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      M[i][j]=random(0,min(r*c,INT_MAX));
    }
  }
}

void print(int **M,int r,int c){
  for(int i=0;i<r;i++){
    cout<<"|";
    for(int j=0;j<c;j++){
      cout<<M[i][j]<<" ";
    }cout<<"\b|"<<endl;
  }
  cout<<endl;
}

int **multiplicar(int **A,int **B,int m,int n,int p){
  int **C;
  C=new int*[m]; for(int i=0;i<m;i++) C[i]=new int[p];
  for(int i=0;i<m;i++){
    int sum=0;
    for(int j=0;j<p;j++){
      for(int k=0;k<n;k++){
        sum+=A[i][k]*B[k][j];
      }
      C[i][j]=sum;
    }
  }
  return C;
}
int main(int argc, char const *argv[]) {

  int m=4,n=4,p=4;
  int **A;
  A=new int*[m]; for(int i=0;i<m;i++) A[i]=new int[n];
  int **B;
  B=new int*[n]; for(int i=0;i<p;i++) B[i]=new int[p];

  randerizar(A,m,n);
  randerizar(B,n,p);

  print(A,m,n);
  print(B,n,p);

  int **C;

  C=multiplicar(A,B,m,n,p);
  print(C,m,p);
  return 0;
}
