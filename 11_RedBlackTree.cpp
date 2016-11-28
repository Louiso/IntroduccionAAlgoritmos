/*
Es aquel arbol que cumple con la sgts propiedades:
  * Todo nodo es rojo o es negro.
  * La raiz es negro
  * Todo NIL es negro
  * Si un nodo es rojo entonces sus dos hijos seran negros.
  * Para cualquier camino siempre habra la misma cantidad de nodos negros.
*/
#include<iostream>
using namespace std;

class Element{
public:
  double value;
  Element(double value){
    this->value=value;
  }
};

template<class T>
class Nodo{
public:
  T *element;
  Nodo *dad;
  Nodo *left;
  Nodo *right;
  Nodo(T *element){
    this->element=element;
    dad=left=right=NULL;
  }
};

template<class T>
class redBlackTree{
public:
  //Indico que tipo de dato ira a guardar Nodo
  Nodo<T> *root;
  int size;
  redBlackTree(){
    root=NULL;
    size=0;
  }
  void printInOrder(Nodo<T> *temp){
    if(temp!=NULL){
      printInOrder(temp->left);
      std::cout << temp->element->value << ' ';
      printInOrder(temp->right);
    }
  }
  void print(){
    printInOrder(root);
  }

  Nodo<T>* searchNodo(Nodo<T>*temp,T *element){
    if(temp==NULL) return NULL;

    if(temp->element->value==element->value) return temp;

    if(element->value<temp->element->value) return searchNodo(temp->left,element);

    if(element->value>temp->element->value) return searchNodo(temp->right,element);
  }
  Nodo<T>* search(T *element){
    return searchNodo(root,element);
  }

  Nodo<T>* minimunNodo(Nodo<T>* nodo){
    while(nodo->left!=NULL){
      nodo=nodo->left;
    }
    return nodo;
  }
  Nodo<T>* maximunNodo(Nodo<T>* nodo){
    while(nodo->right!=NULL){
      nodo=nodo->right;
    }
    return nodo;
  }
  //El sucesor nodo que sigue del nodo anterior:
  Nodo<T>* successor(Nodo<T>* nodo){
    //En el ultimo caso subir de nivel para encontrar un sucesor
    //Mientras tanto verificamos que tenga hijo derecho, ps si lo tiene
    //Entonces su sucesor debe de estar por alli
    if(nodo->right!=NULL){
      return minimunNodo(nodo);
    }
    //En caso que no tenga hijo derecho, verificar que padre es mayor que el
    //Una forma de saber eso es darse cuenta, asignando un nodo temporal que suba el arbol,
    //Hasta que dicho nodo deje de ser hijo derecho, es decir que cuando sea hijo izquierdo
    //Su padre sera mayor que el
    Nodo<T>*dad=nodo->dad;
    while(dad!=NULL && dad->right==nodo){
      nodo=dad;
      dad=dad->dad;
    }
    //Saldra nodo cuando sea hijo izquierdo y dad sea mayor que el
    //Entonces retornamos dad
    return dad;
  }
  bool voidTree(){
    return size==0;
  }
  //Rotaciones:
  void leftRotate(Nodo<T>*nodo){
    Nodo<T>*temp=nodo->right;
    nodo->right=temp->left;
    if(temp->left!=NULL){
      temp->left->dad=nodo;
    }
    temp->dad=nodo->dad;
    if(nodo->dad==root){
      root=temp;
    }else{
      if(nodo==nodo->dad->left){
        nodo->p->left=temp;
      }else{
        nodo->p->right=temp;
      }
    }
    temp->left=nodo;
    nodo->dad=temp;
  }
  void insert(Nodo<T>*nodo){
    Nodo<T>*saveCurr=NULL;
    Nodo<T>*curr=root;
    while(curr!=NULL){
      //Guardamos nuestro nodo actual
      saveCurr=curr;
      if(nodo->element->value<curr->element->value){
        curr=curr->left;
      }else{
        curr=curr->right;
      }
    }
    nodo->dad=saveCurr;
    if(saveCurr==NULL) root=nodo;//Si saveCurr es NULL significa que el nodo esta vacio
    else{
      if(nodo->element->value<saveCurr->element->value) saveCurr->left=nodo;
      else saveCurr->right=nodo;
    }
    size++;
  }
  //////////////////////////////
  //Para borrar un nodo , existen 3 casos posibles:
  // * Si el nodo que queremos borrar no tiene ningun hijo. Facil
  // * Si el nodo que queremos eliminar tiene un hijo, ahora debemos decir que el padre
  //    de ese nodo apunte ahora a ese hijo , ademas que el hijo tambn apunte a al padre de
  //    de ese nodo como padre;
  // * Si el nodo tiene 2 hijos, para ello necesitamos encontrar al sucesor del nodo y se hara que
  //    el sucesor tome el lugar del nodo.
  void transplant(Nodo<T> *u,Nodo<T> *v){
    //Recordar que u se cambiara por v
    if(u->dad==NULL){//Si u es raiz
      root=v;
    }else{//Si u no es raiz
      if(u==u->dad->left){//Si u es hijo izquierdo
        u->dad->left=v;
      }else{
        u->dad->right=v;
      }
    }
    if(v!=NULL){
      v->dad=u->dad;
    }
  }
  // * Primero: Si el nodo no tiene hijo izquierdo, entonces se cual fuese el hijo derecho
  //            se elimina solo transplantando el nodo por el hijo derecho
  // * Segundo: Si el nodo no tiene hijo derecho, entonces se resolvera transplantando el nodo
  //            con el hijo izquierdo
  // * Tercero: En caso que tenga los dos hijos, puede que ocurra:
  //              * El sucesor puede que un hijo del nodo. Y solo hay una posibilidad
  //                El hijo es derecho. Por lo tanto al transplantar el nodo con el hijo derecho,
  //                Debemos recordar que el hijo izquierdo del hijo derecho ahora sera su hermano, es decir
  //                El hijo izquierdo del nodo, ademas que ahora tambn debe reconocerlo como su padre
  //              * El sucesor puede que no sea el hijo derecho del nodo, por lo tanto tomar precaucion antes
  //                de hacer el transplante entre el nodo y el sucesor.
  //                Quiero que el sucesor sea una nueva raiz de un subarbol donde su subraiz es el hijo derecho
  //                nodo, para ello antes debo trasplantar sucesor con su hijo derecho.
  //                De alli recien que el sucesor apunte al hijo derecho del nodo, y que este a la vez lo apunte
  //                como su padre.
  void deleteT(Nodo<T>*nodo){
    if(nodo->left==NULL){//Si nodo no tiene hijo izquierdo,pero el derecho si o no
      transplant(nodo,nodo->right);
    }else{
      if(nodo->right==NULL){//Si nodo no tiene hijo derecho, pero si el izquierdo
        transplant(nodo,nodo->left);
      }else{//Si tiene ambos hijos
        Nodo<T> *sucesor=minimunNodo(nodo->right);
        if(sucesor->dad!=nodo){
          transplant(sucesor,sucesor->right);
          sucesor->right=nodo->right;
          sucesor->right->dad=sucesor;
        }
        transplant(nodo,sucesor);
        sucesor->left=nodo->left;
        sucesor->left->dad=sucesor;
      }
    }
  }
};
int main(int argc, char const *argv[]) {
  redBlackTree<Element> *t=new redBlackTree<Element>();
  t->insert(new Nodo<Element>(new Element(35)));
  t->insert(new Nodo<Element>(new Element(45)));
  t->insert(new Nodo<Element>(new Element(32)));
  t->insert(new Nodo<Element>(new Element(3)));
  t->deleteT(t->search(new Element(32)));
  t->print();
  return 0;
}
