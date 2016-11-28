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

double* countingSort(double *input,int n, int k){
  double *output=new double[n];
  int *contador=new int[k];
  //Inicializando el vector contador de frecuencias
  for(int i=0;i<k;i++){
    contador[i]=0;
  }

  //Vector de frecuencias absolutas
  for(int j=0;j<n;j++){
    contador[(int)input[j]]++;
  }
  print(contador,k);

  for(int i=1;i<k;i++){
    contador[i]+=contador[i-1];
  }
  print(contador,k);

  //Ahora contador contiene las frecuencias acumulativas de los datos.
  for(int j=n-1;j>=0;j--){
    //Recordar que los datos son de 0 a n-1; y por lo tanto es necesario usar -1
    //Ps sin el seria incorrecto. ya que en el acumulativo no existira un valor igual a 0, sino
    //q de 1 a mas .
    output[(int)contador[(int)input[j]]-1]=input[j];
    contador[(int)input[j]]--;
  }
  return output;
  //output Guarda el vector ordenado
}
int main(){

  srand((int)time(0));
  int n=10;
  double *v=new double[n];

  randerizar(v,n);
  print(v,n);
  v=countingSort(v,n,n);
  print(v,n);
  return 0;

}
