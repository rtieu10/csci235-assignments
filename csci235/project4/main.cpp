#include <iostream>
#include "Animal.hpp"
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Fish.hpp"
#include "Node.hpp"
#include "List.hpp"
#include "PrecondViolatedExcep.hpp"
#include "ZooRecord.hpp"





int main(){
  ZooRecord object1("zoo.csv");
  object1.display();
  return 0;
}
