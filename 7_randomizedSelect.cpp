#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits.h>
using namespace std;

int random(int min,int max){
  if(min==max) return min;
  return rand()%(max-min+1) + min;
}

template<class T>
bool buscar(T *vector,int n, int dato){
  for(int i=0;i<n;i++){
    if(vector[i]==dato){
      return true;
    }
  }
  return false;
}


template<class T>
void print(T *vector,int n){
  cout<<"{";
  for(int i=0;i<n;i++){
    cout << vector[i] << " ";
  }cout<<"\b}"<<endl;
}

void randerizar(double *vector,int n){
  for(int i=0;i<n;i++){
    int temp;
    do{
      temp=random(0,1000);
    }while(buscar(vector,i,temp));
    vector[i]=temp;
  }
}

template<class T>
void exchange(T &a,T &b){
  T temp=a;
  a=b;
  b=temp;
}

template<class T>
int partition(T *vector,int start, int end){
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

template<class T>
int randomizedPartition(T *vector,int start,int end){
  //Toma un indice aleatorio
  int i=random(start,end);
  //Se cambia el elemento aleatorio con el ultimo
  exchange(vector[i],vector[end]);
  return partition(vector,start,end);

}

//Se busca el i-esimo elemento menor del vector
template<class T>
T randomizedSelect(T *vector,int start,int end, int i){
  if(start==end){
    std::cout << "s" << '\n';
    return vector[start];
  }else{
    //Partimos el vector en 2 partes , de manera aleatoria respecto a un punto cuyo indice
    //es q y valor es vector[q].
    int q=randomizedPartition(vector,start,end);
    std::cout << "q : " << q  << " vector[q] : " << vector[q] << '\n';
    print(vector,10);
   //tamaño del subvector menor, desde start hasta q
   //recordando que q es el elemento q -esimo menor de la izquierda respecto a start
   //Supongamos que k es el nuevo tamaño de un vector izquierdo, cuyo indice inicial es start
   int k=q-start+1;
   if(q==i){
     std::cout << "e" << '\n';
     //si el tamaño del primer subvector es igual al lugar q estamos buscando
     return vector[q];
   }else{
     if(i<q){
       std::cout << "l" << '\n';
       return randomizedSelect(vector,start,q-1,i);
     }else{
       std::cout << "r" << '\n';
       //std::cout << "JAAAAAAA" << '\n';
       return randomizedSelect(vector,q+1,end,i);
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
  int i=5;
  double p=randomizedSelect(v,0,n-1,i);
  //Empezando desde 0
  std::cout << "el "<<i<<"th menor numero es : " << p << '\n';
  //cout<<v[randomizedPartition(v,0,n-1)]<<endl;
  print(v,n);
  return 0;

}
