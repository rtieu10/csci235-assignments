#include <iostream>
#include "Animal.cpp"
#include "ArrayBag.hpp"


int main(){

  ArrayBag<int> testarray; //int type using templates???
  testarray.add(1);
  testarray.add(2);
  testarray.add(3);
  testarray.add(4);
  testarray.display();

  ArrayBag<int> testarray1;
  testarray1.add(10);
  testarray1.add(11);
  testarray1.add(12);
  testarray1.add(2);
  testarray1.add(3);
  testarray1.add(4);
  testarray1.display();

  testarray.operator+=(testarray1);  //creating the union between both
  testarray.display();  //displaying the result

  testarray.operator-=(testarray1);  //modified the testarray1
  testarray.display();

  testarray.operator /=(testarray1);
  testarray.display();

}
