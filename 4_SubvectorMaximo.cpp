//Supongamos que tenemos un array que almacena los precios de un determinado
//Producto en un determinado tiempo, Se busca optener la mejor ganancia
//si en un dia se compra y en otro se vende.
//Para realizar esta busqueda se crea otro array que almacena los incremento y decremento
//De un dia respecto de otro.
//Una forma de saber esto es calculando una submatriz que de la mayor suma, el cual
//Representara el camino que tuvo que recorrer para llegar de un punto a otro punto
//Es decir la diferencia de un punto a otro punto.
#include<iostream>
#include<cstdlib>
#include<limits.h>
#include<ctime>
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

int *maxSubvectorCruzado(int *vector,int start,int mid,int end){
  int left_sum=-INT_MAX;
  int sum=0;
  int max_left=mid;
  for(int i=mid;i>=start;i--){
    sum+=vector[i];
    if(sum>left_sum){
      left_sum=sum;
      max_left=i;
    }
  }
  int right_sum=-INT_MAX;
  sum=0;
  int max_right=mid+1;
  for(int i=mid+1;i<=end;i++){
    sum+=vector[i];
    if(sum>right_sum){
      right_sum=sum;
      max_right=i;
    }
  }
  int *temp=new int[3];
  temp[0]=max_left;
  temp[1]=max_right;
  temp[2]=left_sum+right_sum;
  return temp;
}

int * maxSubvector(int *vector,int start,int end){
  if(end<=start){
    int *temp=new int[3];
    temp[0]=start;
    temp[1]=end;
    temp[2]=vector[start];
    return temp;
  }else{
    int mid=(start+end)/2;
    int *left=maxSubvector(vector,start,mid);
    int *right=maxSubvector(vector,mid+1,end);
    int *center=maxSubvectorCruzado(vector,start,mid,end);
    //Si la suma de izquierda es mayor q la del resto entonces retorna left.
    //Si la suma de centro es mayor que la de izquierda y derecha entonces retorna centro.
    //Si la suma de derecha es mayot que la de izquierda y centro entonces retorna derecha.
    if(left[2]>=right[2] && left[2]>=center[2]){
      return left;
    }
    if(center[2]>=left[2] && center[2]>=right[2]){
      return center;
    }
    if(right[2]>=left[2] && right[2]>=center[2]){
      return right;
    }
  }
}

int *incrementos(int *v,int n){
  int *temp=new int[n];
  for(int i=1;i<n;i++){
    temp[i]=v[i]-v[i-1];
  }
  temp[0]=0;
  return temp;
}

int main(int argc, char const *argv[]) {
  srand((int)time(0));
  int n=100;
  int *v = new int[n];
  randerizar(v,n);
  print(v,n);
  int *incts=incrementos(v,n);
  print(incts,n);
  int *temp=maxSubvector(incts,1,n-1);
  //v[temp[0]-1];  se debe a que antes de que suban los precios uno ya debe comprar.
  std::cout << "Valor de compra : " << v[temp[0]-1] << "\nValor de venta : " << v[temp[1]] << "\nGanancia obtenida : " << temp[2]<<'\n';
  return 0;
}
