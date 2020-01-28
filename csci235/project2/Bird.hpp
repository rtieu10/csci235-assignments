#include <iostream>
#include "Animal.hpp"

using std::string;

class Bird:public Animal{
public:
  Bird();
  Bird(string name, bool domestic = false, bool predator = false);
  bool isAirborne() const;
  bool isAquatic() const;
  void setAirborne();
  void setAquatic();
private:
  bool airborne_;
  bool aquatic_;

};
