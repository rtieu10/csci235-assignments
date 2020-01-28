#pragma once

#include <iostream>
#include <string>



class Animal{
  public:   //member functions stored in public
    Animal();
    //if the parameters for domestic and predator are blank, it will automatically fill in false
    Animal(std::string name, bool domestic = false, bool predator = false);
    std::string getName() const; //values from these functions stay constant
    bool isDomestic() const;
    bool isPredator() const;
    void setName(std::string name);
    void setDomestic();
    void setPredator();
    friend bool operator==(const Animal& animalobj, const Animal& animalobj1); //check if teverything is the same all the way through
    virtual void display() const = 0;  //no implementation in base class
  protected:      //private variables stored here
    std::string name_;
    bool domestic_;
    bool predator_;

};
