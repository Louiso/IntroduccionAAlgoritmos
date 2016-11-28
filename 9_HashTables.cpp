#include<iostream>

using namespace std;
const int size=15;
// class Element{
// public:
//   int value;
//   int key;
//   Element(int value=0){
//     this->value=value;
//     this->key=value%size;
//   }
// };
class Element{
public:
  int value;
  int key;
  Element(int value){
    this->value=value;
    this->key=value%size;
  }
};
template<class T>
class Nodo{
public:
  T *dato;
  Nodo *sgt;
  Nodo *prev;
  Nodo(T *dato){
    this->dato=dato;
    sgt=NULL;
    prev=NULL;
  }
};

template<class T>
class List{
public:
  Nodo<T> *start;
  Nodo<T> *end;
  int size;
  List(){
    size=0;
  }
  bool voidList(){
    return size==0;
  }
  void insertTop(Nodo<T> *nuevo){
    if(voidList()){
      start=nuevo;
      end=nuevo;
    }else{
      //recorrer la lista hasta ser el final
      end->sgt=nuevo;
      nuevo->prev=end;
      end=nuevo;
    }
    size++;
  }
  void insertTail(Nodo<T> *nuevo){
    if(voidList()){
      start=nuevo;
      end=nuevo;
    }else{
      //recorrer la lista hasta ser el final
      nuevo->sgt=start;
      start->prev=nuevo;
      start=nuevo;
    }
    size++;
  }

  void deleteList(Nodo<T> *nodo){
    if(size!=0){
      if(nodo->prev!=NULL){
        nodo->prev->sgt=nodo->sgt;
      }else{
        start=nodo->sgt;
      }
      if(nodo->sgt!=NULL){
        nodo->sgt->prev=nodo->prev;
      }else{
        end=nodo->prev;
      }
      size--;
    }
  }
  void printQueue(){
    for(Nodo<T> *i=start;i!=NULL;i=i->sgt){
      std::cout << i->dato->value << " ";
    }
    std::cout << '\n';
  }
  void printStack(){
    for(Nodo<T> *i=end;i!=NULL;i=i->prev){
      std::cout << i->dato->value << " ";
    }
    std::cout << '\n';
  }
  Nodo<T>* search(T dato){
    for(Nodo<T> *i=start;i!=NULL;i=i->sgt){
      if(i->dato==dato){
        return i;
      }
    }
    return NULL;
  }
};
class HashTable{
public:
  List<Element> **tabla;
  HashTable(){
    tabla=new List<Element>*[size];
    for(int i=0;i<size;i++) tabla[i]=new List<Element>;
  }
  void hashInsert(Element *x){
    tabla[(int)x->key]->insertTail(new Nodo<Element>(x));
  }
  void print(){
    for(int i=0;i<size;i++){
      tabla[i]->printQueue();
    }
  }
};

int main(int argc, char const *argv[]) {
  HashTable *hash=new HashTable();
  hash->hashInsert(new Element(12));
  hash->hashInsert(new Element(54));
  hash->hashInsert(new Element(45));
  hash->hashInsert(new Element(15));
  hash->hashInsert(new Element(30));
  hash->print();
  // lista->printStack();
  // lista->deleteList(lista->search(123));
  // lista->printQueue();
  //Nodo<double> *temp=lista->search(15);
  //std::cout << (temp!=NULL?temp->dato:-1) << '\n';
  return 0;
}
