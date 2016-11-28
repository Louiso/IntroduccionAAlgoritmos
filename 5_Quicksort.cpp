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

void exchange(double &a,double &b){
  double temp=a;
  a=b;
  b=temp;
}
int partition(double *vector,int start, int end){
  //X almacena el ultimo valor
  int x=vector[end];
  //i almacena un valor menor que el de inicio:
  int i=start-1;
  //Aqui empieza la comparacion con todo el subvector creado
  for(int j=start;j<end;j++){
    //Si el elemento es menor que el ultimo entonces,se incrementa la "pila".
    if(vector[j]<=x){
      i++;
      exchange(vector[i],vector[j]);
    }
  }
  //terminando : i almacenara el ultimo valor menor que el final
  //Por lo tanto el intercambio se da entre i+1 y final;
  exchange(vector[i+1],vector[end]);
  //Se retorna i+1, que es la posicion del valor del ultimo.
  return i+1;
}

//Para ordenar primero debo ordenar la parte de izquierda y la parte derecha , de los cuales:
//La parte izquierda se sabe q es menor que q y la parte derecha es mayor que q
void quickSort(double *vector,int start,int end){
  if(start<end){
    int q=partition(vector,start,end);
    quickSort(vector,start,q-1);
    quickSort(vector,q+1,end);
  }
}
int main(){

  srand((int)time(0));
  int n=10;
  double *v=new double[n];

  randerizar(v,n);
  print(v,n);
  quickSort(v,0,n-1);
  print(v,n);
  return 0;

}
