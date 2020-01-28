#include <iostream>
#include "Animal.hpp"

using std::string;

class Fish:public Animal{
  public:
    Fish();
    Fish(string name, bool domestic = false, bool predator = false);
    bool isVenomous() const;
    void setVenomous();
  private:
    bool venomous_;
};
