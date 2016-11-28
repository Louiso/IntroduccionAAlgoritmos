#include<iostream>

using namespace std;

const int size=15;
class Element{
public:
  int value;
  int key;
  Element(int value=0){
    this->value=value;
    this->key=value%size;
  }
};

class DirectHashTables{
public:
  Element **tabla;
  DirectHashTables(){
    tabla=new Element*[size];
    for(int i=0;i<size;i++) tabla[i]=new Element();
  }
  Element* directSearch(int k){
    return tabla[k];
  }
  void directInsert(Element *x){
    tabla[x->key]=x;
  }
  void directDelete(Element *x){
    tabla[x->key]=NULL;
  }
  void print(){
    for(int i=0;i<size;i++){
      std::cout << tabla[i]->value << " ";
    }
    std::cout << '\n';
  }
};
int main(int argc, char const *argv[]) {

  DirectHashTables *hash=new DirectHashTables();
  hash->directInsert(new Element(12));
  hash->directInsert(new Element(23));
  hash->directInsert(new Element(8));
  hash->print();
  return 0;
}
