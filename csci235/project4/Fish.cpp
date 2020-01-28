#include "Fish.hpp"


Fish::Fish(){  //default constructor, if theres no params it wil run this constructor
  venomous_ = false;
  domestic_ = false;
  predator_ = false;
  name_ ="";
}

Fish::Fish(std::string name, bool domestic, bool predator){  //if there are params passed through for domestic and predator, it will run this constructor
  name_= name;              //make sure to give all the variables a value in both constructors
  domestic_ = domestic;
  predator_ = predator;
  venomous_ = false;
}

bool Fish::isVenomous() const{
  if(venomous_ == true){
    return true;
  }
    return false;
}

void Fish::setVenomous(){
  venomous_ = true;
}

void Fish::display() const{
  std::string result = "";
  if(isDomestic()==false){
    result = result + getName() + " is not domestic, ";
  }
  else{
    result = result + getName() + " is domestic, ";
  }

  if(isPredator() == false){
    result = result + "is not a predator\n";
  }
  else{
    result = result + "it is a predator\n";
  }

  if(isVenomous() == false){
    result = result + "and it is not venomous.\n\n";
  }
  else{
    result = result + "and it is venemous.\n\n";
  }

  std::cout << result;
}
