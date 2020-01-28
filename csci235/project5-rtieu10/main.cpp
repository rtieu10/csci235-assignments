#include <iostream>
#include "PrecondViolatedExcep.hpp"
#include "Node.hpp"
#include "LinkedList.hpp"
int main(){
  LinkedList<int>* x = new LinkedList<int>;
  LinkedList<int>* y = new LinkedList<int>;
  for(int i = 0; i < 10; i++){    //use a for loop to insert elements into the linked list
    x-> insert(x->getLength(), i);
    y-> insert(y->getLength(), i);
  }

  x->invert();
  y->rotate(2);

  for(int i = 0; i < x->getLength(); i++){   //print each elem in the linked list
    std::cout << x->getEntry(i) << " ";
  }
    std::cout << std::endl;   //prints out on a new line 

  for(int i = 0; i < y->getLength(); i++){  //print each elem in the linked list
    std::cout << y->getEntry(i) << " ";
  }
  std::cout << std::endl;

}
