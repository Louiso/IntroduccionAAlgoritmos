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

void merge(double *vector,int start,int medio,int end){
  //Luego de haber ordenado ya los pequeños vectores , pasaremos a ordenar el vector grande
  //Pasaremos los valores de cada mitad a otros vectores
  int tamL=medio-start+1;
  int tamR=end-medio;
  double *L=new double[tamL];
  double *R=new double[tamR+1];
  //Pasando los valores del vector a otros vectores
  for(int i=0;i<tamL;i++){
    L[i]=vector[start+i];
  }
  L[tamL]=LONG_MAX;

  for(int i=0;i<tamR;i++){
    R[i]=vector[medio+1+i];
  }
  R[tamR]=LONG_MAX;
  //Ahora pasamos los valores de cada vector al vector original de manera ordenada
  int i=0;
  int j=0;
  for(int k=0;k<(tamL+tamR);k++){
    if(L[i]<R[j]){
      vector[start+k]=L[i];
      i++;
    }else{
      vector[start+k]=R[j];
      j++;
    }
  }

}
void mergeSort(double *vector,int start,int end){
  //Busco ordenar un vector, pero se ve muy complicado
  //Por el cual me veo en obligacion a usar recursividad para hacerlo
  //Mas facil.... para ordenar un vector grande primero tengo que ordenar
  //Los vectores mas chicos q tendran la mitad del tamaño del vector a ordenar
  if(start<end){
    int medio=(start+end)/2;
    mergeSort(vector,start,medio);
    mergeSort(vector,medio+1,end);
    merge(vector,start,medio,end);
  }
}

//Analisis del algoritmo mergeSort
//T(n)={
        // O_(1) , si n=1
        // 2T(n/2) + O_(n) , si n>1
//}
//Como n^log2(2)=n
//Entonces:
  // T(n)=O_(nlgn)
int main(){

  srand((int)time(0));
  int n=10;
  double *v=new double[n];

  randerizar(v,n);
  print(v,n);
  mergeSort(v,0,n-1);
  print(v,n);
  return 0;

}
