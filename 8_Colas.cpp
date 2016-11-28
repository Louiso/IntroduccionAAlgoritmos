#include<iostream>

using namespace std;

const int MAX=100;
template<class T>
class Queue{
public:
  T *v;
  int tail;
  int head;
  Queue(){
    v=new T[MAX];
    tail=-1;
    head=-1;
  }
  bool voidQueue(){
    return tail==-1 && head==-1;
  }
  void enqueue(T dato){
    if(voidQueue()){
      tail++;
    }
    head++;
    v[head]=dato;
  }
  T dequeue(){
    tail++;
    return v[tail-1];
  }
  void print(){
    for(int i=tail;i<=head;i++){
      std::cout << v[i] << " ";
    }
    std::cout << '\n';
  }
};

int main(int argc, char const *argv[]) {
  Queue<double> *cola=new Queue<double>();
  cola->enqueue(23);
  cola->enqueue(34);
  cola->enqueue(24);
  cola->enqueue(256);
  cola->enqueue(123);
  cola->print();
  cola->dequeue();
  cola->print();
  return 0;
}
