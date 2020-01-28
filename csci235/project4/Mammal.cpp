#include "Mammal.hpp"


Mammal::Mammal(){  //default constructor, will run when no params are passed, each val needs a value
  name_= "";
  domestic_=false;
  predator_=false;
  hair_ = false;
  airborne_ = false;
  aquatic_ = false;
  toothed_ = false;
  fins_ = false;
  tail_ = false;
  legs_ = 0;
}

Mammal::Mammal(std::string name, bool domestic, bool predator){ //will run when params are given, each var need a value
  name_ = name;
  domestic_ = domestic;
  predator_ = predator;
  hair_ = false;
  airborne_ = false;
  aquatic_ = false;
  toothed_ = false;
  fins_ = false;
  tail_ = false;
  legs_ = 0;
}


bool Mammal::hasHair() const{
  return hair_;
}

bool Mammal::isAirborne() const{
  return airborne_;
}

bool Mammal::isAquatic() const{
  return aquatic_;
}

bool Mammal::isToothed() const{
  return toothed_;
}

bool Mammal::hasFins() const{
  return fins_;
}

bool Mammal::hasTail() const{
  return tail_;
}

int Mammal::legs() const{  //not sure if thi is correct
  return legs_;
}

void Mammal::setHair(){  //changes values to true
  hair_ = true;
}

void Mammal::setAirborne(){
  airborne_ = true;
}

void Mammal::setAquatic(){
  aquatic_ = true;
}

void Mammal::setToothed(){
  toothed_ = true;
}

void Mammal::setFins(){
  fins_ = true;
}

void Mammal::setTail(){
  tail_ = true;
}

void Mammal::setLegs(int legs){
  legs_ = legs;
}

void Mammal::display() const{
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
    result = result + "and it is not aquatic,\n";
  }
  else{
    result = result + "and it is aquatic,\n";
  }

  if(hasHair() == false){
    result = result + "it has no hair, ";
  }
  else{
    result = result + "it has hair, ";
  }

  if(isToothed() == false){
    result = result + "no teeth, ";
  }
  else{
    result = result + "teeth, ";
  }

  if(hasFins() == false){
    result = result + "no fins, ";
  }
  else{
    result = result + "fins, ";
  }

  if(hasTail() == false){
    result = result + "no tail and ";
    result = result + std::to_string(legs()) + " legs.\n\n";
  }
  else{
    result = result + "tail and ";
    result = result + std::to_string(legs()) + " legs.\n\n";
  }

  std::cout << result;
}
