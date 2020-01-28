#include "Fish.hpp"

using std::string;

Fish::Fish(){  //default constructor, if theres no params it wil run this constructor
  venomous_ = false;
  domestic_ = false;
  predator_ = false;
  name_ ="";
}

Fish::Fish(string name, bool domestic, bool predator){  //if there are params passed through for domestic and predator, it will run this constructor
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
