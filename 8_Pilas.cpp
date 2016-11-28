#include<iostream>
using namespace std;

const int MAX=100;
template<class T>
class Stack{
public:
  int top;
  T *v;
  Stack(){
    v=new T[MAX];
    top=-1;
  }
  bool voidStack(){
    return top==-1;
  }
  void push(T dato){
    top++;
    v[top]=dato;
  }
  T pop(){
    if(voidStack()){
      cerr << "Pila vacia"<<endl;
    }else{
      top--;
      return v[top+1];
    }
  }

  void print(){
    for(int i=0;i<=top;i++)
      cout<<v[i]<<" ";
  }

};

int main(int argc, char const *argv[]) {
  Stack<double> *pila=new Stack<double>();
  pila->push(12.3);
  pila->push(1.34);
  pila->push(3.45);
  pila->print();
  return 0;
}
