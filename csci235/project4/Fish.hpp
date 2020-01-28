#pragma once
#include <iostream>
#include "Animal.hpp"
#include <string>


class Fish:public Animal{
  public:
    Fish();
    Fish(std::string name, bool domestic = false, bool predator = false);
    bool isVenomous() const;
    void setVenomous();
    virtual void display() const override;
  private:
    bool venomous_;
};
