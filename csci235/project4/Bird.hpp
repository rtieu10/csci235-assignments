#pragma once
#include <iostream>
#include "Animal.hpp"
#include <string>

class Bird:public Animal{
public:
  Bird();
  Bird(std::string name, bool domestic = false, bool predator = false);
  bool isAirborne() const;
  bool isAquatic() const;
  void setAirborne();
  void setAquatic();
  virtual void display() const override;
private:
  bool airborne_;
  bool aquatic_;

};
