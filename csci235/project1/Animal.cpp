#include "Animal.hpp"


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

//if domesic is true, it returns true, otherwise returns false
bool Animal::isDomestic() const{
  /**if(domestic_ == true){
    return true;
  }
  else{
    return false;
  }**/
  return domestic_;
}

//if prefator is true, it returns true, otherwise returns true
bool Animal::isPredator() const{
  /**if(predator_ == true){
    return true;
  }
  else{
    return false;
  }**/
  return predator_;
  }
