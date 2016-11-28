#include<iostream>
using namespace std;

class Element{
public:
  double value;
  Element(double value=0){
    this->value=value;
  }
};

// La clase nodo es un punto que guarda un dato en especifico.
template<class T>
class Nodo{
public:
  T *element;
  Nodo *sgt;
  Nodo *prev;
  Nodo(T *element){
    this->element=element;
    sgt=NULL;
    prev=NULL;
  }
};


int main(int argc, char const *argv[]) {
  Nodo<Element> *nodo=new Nodo<Element>(new Element(12));
  std::cout << nodo->element->value << '\n';
  return 0;
}
