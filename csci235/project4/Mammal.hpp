#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Animal.hpp"

class Mammal:public Animal {
public:
  Mammal();
  Mammal(std::string name, bool domestic = false, bool predator = false);
  bool hasFins() const;
  bool hasTail() const;
  bool hasHair() const;
  bool isAirborne() const;
  bool isAquatic() const;
  bool isToothed() const;
  int legs() const;
  void setHair();
  void setAirborne();
  void setAquatic();
  void setToothed();
  void setFins();
  void setTail();
  void setLegs(int legs);
  virtual void display() const override;
private:
  bool hair_;
  bool airborne_;
  bool aquatic_;
  bool toothed_;
  bool fins_;
  bool tail_;
  int legs_;
};
