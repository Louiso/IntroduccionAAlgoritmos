#include<iostream>

using namespace std;

template<class T>
class Nodo{
public:
  T dato;
  Nodo *sgt;
  Nodo *prev;
  Nodo(){
    dato=0;
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
  void insertTop(T dato){
    Nodo<T> *nuevo=new Nodo<T>();
    nuevo->dato=dato;
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
  void insertTail(T dato){
    Nodo<T> *nuevo=new Nodo<T>();
    nuevo->dato=dato;
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
      std::cout << i->dato << " ";
    }
    std::cout << '\n';
  }
  void printStack(){
    for(Nodo<T> *i=end;i!=NULL;i=i->prev){
      std::cout << i->dato << " ";
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
int main(int argc, char const *argv[]) {
  List<double> *lista=new List<double>();
  lista->insertTail(134);
  lista->insertTop(123);
  lista->insertTail(12);
  lista->insertTop(24);
  lista->printQueue();
  lista->printStack();
  lista->deleteList(lista->search(123));
  lista->printQueue();
  //Nodo<double> *temp=lista->search(15);
  //std::cout << (temp!=NULL?temp->dato:-1) << '\n';
  return 0;
}
