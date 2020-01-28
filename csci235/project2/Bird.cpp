#include "Bird.hpp"

using std::string;

Bird::Bird(){   //default constructors, this will run if no params are passed
  name_ = "";
  domestic_ = false;
  predator_ = false;
  airborne_ = false;
  aquatic_ = false;

}

Bird::Bird(string name, bool domestic, bool predator){ //this will run w/ params, which is why every var needs a value
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
