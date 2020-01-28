#include <iostream>
#include "Animal.hpp"

using std::string;

void test(Animal* animal){
  std::cout<<animal->getName()<<" ";

  if(animal->isDomestic()){
    std::cout<<"true ";
  }
  else{
    std::cout<<"false ";
  }

  if(animal->isPredator()){
    std::cout<<"true ";
  }
  else{
    std::cout<<"false ";
  }
  std::cout<<std::endl;
}


int main(){

  Animal* a = new Animal();
  Animal* b = new Animal("imgey");
  Animal* c = new Animal("verygey", true, false);

  test(a);
  test(b);
  test(c);

  return 0;
}
