#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits.h>
using namespace std;

int random(int min,int max){
  return rand()%(max-min+1) + min;
}

void randerizar(double *vector,int n){
  for(int i=0;i<n;i++){
    vector[i]=random(0,n-1);
  }
}

template<class T>
void print(T *vector,int n){
  cout<<"{";
  for(int i=0;i<n;i++){
    cout << vector[i] << " ";
  }cout<<"\b}"<<endl;
}

void exchange(double &a,double &b){
  double temp=a;
  a=b;
  b=temp;
}

void radixSort(){
  int d;
  for(int i=1;i<d;i++){
    
  }
}

int main(){

  srand((int)time(0));
  int n=10;
  double *v=new double[n];

  randerizar(v,n);
  print(v,n);

  print(v,n);
  return 0;

}
