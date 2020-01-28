#include "Bird.hpp"


Bird::Bird(){   //default constructors, this will run if no params are passed
  name_ = "";
  domestic_ = false;
  predator_ = false;
  airborne_ = false;
  aquatic_ = false;

}

Bird::Bird(std::string name, bool domestic, bool predator){ //this will run w/ params, which is why every var needs a value
  name_ = name;
  domestic_ = domestic;
  predator_ = predator;
  airborne_ = false;
  aquatic_ = false;
  }

bool Bird::isAirborne() const{
  if(airborne_ == true){
    return true;
  }
  return false;
}

bool Bird::isAquatic() const{
  if(aquatic_ == true){
    return true;
  }
  return false;
}

void Bird::setAirborne(){
  airborne_ = true;
}

void Bird::setAquatic(){
  aquatic_ = true;
}

void Bird::display() const{

  std::string result = "";

  if(isDomestic() == false){
    result = result + getName() + " is not domestic ";
  }
  else{
    result = result + getName() + " is domestic ";
  }

  if(isPredator() == false){
    result = result + "and is not a predator,\n";
  }
  else{
    result = result + "and it is a predator,\n";
  }

  if(isAirborne() == false){
    result = result + "it is not airborne ";
  }
  else{
    result = result + "it is airborne ";
  }

  if(isAquatic() == false){
    result = result + "and it is not aquatic.\n\n";
  }
  else{
    result = result + "and it is aquatic.\n\n";
  }

  std::cout << result;
}
