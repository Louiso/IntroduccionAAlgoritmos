#include<iostream>
#include<cstdlib>
#include<ctime>

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

//Hora de hacer una algoritmo de insertSort
void insertSort(double *vector,int n){
  for(int i=1;i<n;i++){//----------------------> n
    double temp=vector[i];//-------------------> (n-1)
    int j;//-----------------------------------> (n-1)
    for(j=i-1;j>=0 && temp<vector[j];j--){//---> Sumatoria{1->n-1}:tj
      vector[j+1]=vector[j];//-----------------> Sumatoria(1->n-1)(tj-1)
    }
    vector[j+1]=temp;//------------------------> n-2
  }
}
//En el mejor de los casos tj tiene el valor de 1, entonces T(n)=n;
//EN el peor de los casos tj tiene el valor de i, entonces T(n)=n^2;
int main(){

  srand((int)time(0));
  int n=10;
  double *v=new double[n];

  randerizar(v,n);
  print(v,n);
  insertSort(v,n);
  print(v,n);
  return 0;

}
