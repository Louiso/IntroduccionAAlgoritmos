#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits.h>
using namespace std;

int random(int min,int max){
  return rand()%(max-min+1) + min;
}

void randerizar(int *vector,int n){
  for(int i=0;i<n;i++){
    vector[i]=random(0,n);
  }
}

void print(int *vector,int n){
  cout<<"{";
  for(int i=0;i<n;i++){
    cout << vector[i] << " ";
  }cout<<"\b}"<<endl;
}

int parent(int i){
  return i/2;
}

int left(int i){
  return 2*i;
}

int right(int i){
  return 2*i+1;
}

//Heap size es el tamaño del vector

int heapSize;

//Lo que hace esta funcion es poner los valores maximos en la cabeza de cada nivel
//Desde donde se le indique hacerlo
void maxHeapify(int *vector,int i){
  int l=left(i);
  int r=right(i);
  int largest;
  if(l<heapSize && vector[l]>vector[i]){
    largest=l;
  }else{
    largest=i;
  }
  if(r<heapSize && vector[r]>vector[largest]){
    largest=r;
  }
  if(largest!=i){
    int temp=vector[i];
    vector[i]=vector[largest];
    vector[largest]=temp;
    maxHeapify(vector,largest);
  }
}

void buildMaxHeap(int *vector,int n){
  heapSize=n;
  for(int i=n/2;i>=0;i--){
    maxHeapify(vector,i);
  }
}
void heapSort(int *vector,int n){
  //Con esto se construye la estructura de arbol que cumplia las caracteristicas
  buildMaxHeap(vector,n);
  print(vector,n);
  //La estructura construida consta de un vector que simula un arbol, donde la raiz tiene el mayor valores
  //Luego dicho valor se cambia con el "ultima" posicion , para asi estar creando un arbol ordenado
  //de final a comienzo... Luego de modificar el arbol, se tiene que hacer una reparacion, para ello se hace uso
  //maxHeapify nuevamente , pero esta vez con un tamaño menor , ps uno ya ha sido salvado.
  for(int i=n-1;i>=1;i--){
    int temp=vector[0];
    vector[0]=vector[i];
    vector[i]=temp;
    heapSize--;
    maxHeapify(vector,0);
  }
}

int heapMaximun(int *vector){
  return vector[0];
}

int heapExtractMax(int *vector){
  if(heapSize<1){
    cerr << "Heap Underflow!!" << '\n';
  }
  int max=vector[0];
  vector[0]=vector[heapSize-1];
  vector[heapSize-1]=0;
  heapSize--;
  maxHeapify(vector,0);
  return max;
}

void heapIncreaseKey(int *vector,int i,int key){
  if(key<vector[i]){
    std::cerr << "El nuevo valor is mas pequeño que el actual" << '\n';
  }
  vector[i]=key;
  //Lo que hace esto es tratar de subir el valor de i en lo mas alto posible.
  while(i>0 && vector[parent(i)]<vector[i]){
    int temp=vector[i];
    vector[i]=vector[parent(i)];
    vector[parent(i)]=temp;
    i=parent(i);
  }
}

void maxHeapInsert(int *vector,int key){
  heapSize++;
  vector[heapSize-1]=INT_MIN;
  heapIncreaseKey(vector,heapSize-1,key);
}
int main(){

  srand((int)time(0));
  int n=10;
  int *v=new int[n];

  randerizar(v,n);
  print(v,n);
  buildMaxHeap(v,n);
  print(v,heapSize);
  std::cout << "El valor maximo es : " << heapMaximun(v) << '\n';
  //heapExtractMax(v);
  std::cout << "Extrayendo el valor maximo ... el nuevo valor maximo ahora es : " << heapMaximun(v) << '\n';
  //heapSort(v,n);
  print(v,heapSize);
  maxHeapInsert(v,20);
  print(v,heapSize);
  heapExtractMax(v);
  print(v,heapSize);
  return 0;

}
