#include "Mammal.hpp"

using std::string;

Mammal::Mammal(){  //default constructor, will run when no params are passed, each val needs a value
  name_="";
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

Mammal::Mammal(string name, bool domestic, bool predator){ //will run when params are given, each var need a value
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
  if(hair_ == true){
    return true;
  }
  return false;
}

bool Mammal::isAirborne() const{
  if(airborne_ == true){
    return true;
  }
  return false;
}

bool Mammal::isAquatic() const{
  if(aquatic_ == true){
    return true;
  }
  return false;
}

bool Mammal::isToothed() const{
  if(toothed_ == true){
    return true;
  }
  return false;
}

bool Mammal::hasFins() const{
  if(fins_ == true){
    return true;
  }
  return false;
}

bool Mammal::hasTail() const{
  if(tail_ == true){
    return true;
  }
  return false;
}

int Mammal::legs() const{  //not sure if thi is correct
  return legs_;
}

void Mammal::setHair(){
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
