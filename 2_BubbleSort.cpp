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
    vector[i]=random(0,n);
  }
}

void print(double *vector,int n){
  cout<<"{";
  for(int i=0;i<n;i++){
    cout << vector[i] << " ";
  }cout<<"\b}"<<endl;
}

void bubbleSort(double *vector,int n){
  //Tomamos como pivote todos los elementos de n , desde el inicio hasta el penultimo elemento
  for(int i=0;i<n-1;i++){
    //Lo que hara esto es refinar cada vez el orden del vector
    for(int j=n-1;j>i;j--){
      if(vector[j]<vector[j-1]){
        double temp=vector[j];
        vector[j]=vector[j-1];
        vector[j-1]=temp;
      }
    }
  }
}
int main(){

  srand((int)time(0));
  int n=10;
  double *v=new double[n];

  randerizar(v,n);
  print(v,n);
  bubbleSort(v,n);
  print(v,n);
  return 0;

}
