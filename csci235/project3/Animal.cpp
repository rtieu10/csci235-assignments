#include "Animal.hpp"
#include <iostream>

using std::string;

//the constructor which intializes the ojects in the class
Animal::Animal(){
  name_="";
  predator_=false;
  domestic_=false;
}

//sets the pow taramters equal to the member variables in the class
Animal::Animal(string name, bool domestic, bool predator){
  domestic_ = domestic;
  predator_ = predator;
  name_ = name;
}

//returns the value stored at the member varaible in the class
string Animal::getName() const{
  return name_;
}

//sets the name variable from the class to the parameter set in the function
void Animal::setName(string name){
  name_ = name;
}

//if domestic is false, then it will be set to true, otherwise it iwll be false
void Animal::setDomestic(){
  /**if(domestic_ == false){
    domestic_ =true;
  }
  else{
    domestic_ = false;
  }**/
  domestic_=true;
}

//if predator is false, it gets set to true, otherwise it is false
void Animal::setPredator(){
  /**if(predator_ == false){
    predator_ = true;
  }
  else{
    predator_ = false;
  }**/
  predator_=true;
}

bool Animal::isDomestic() const{

  return domestic_;
}

//if prefator is true, it returns true, otherwise returns true
bool Animal::isPredator() const{

  return predator_;
  }


bool operator==(const Animal& animalobj, const Animal& animalobj1){

//all the names are stored in the animal class
//referring to the functions in the animal class, and getting the variables
  if(animalobj.getName() == animalobj1.getName() && animalobj.isPredator() == animalobj1.isPredator() && animalobj.isDomestic() == animalobj1.isDomestic()){
    return true;
  }
  return false;
}

void Animal::display(){
    if(isDomestic()== false && isPredator() == false){    //just print if its domestic and predator
      std::cout << getName() << " is not domestic and is not a predator" << std::endl;
    }
    if(isDomestic() == true && isPredator() == true){
      std::cout << getName() << " is domestic and it is a predator" << std::endl;
    }
    if(isDomestic() == true && isPredator() == false){
      std::cout << getName() << " is domestic and is not a predator" << std::endl;
    }
    if(isDomestic() == false && isPredator() == true){
      std::cout << getName() << " is not domestic and it is a predator" << std::endl;
    }

  }
