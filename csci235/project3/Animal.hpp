#pragma once

#include <iostream>

using std::string;


class Animal{
  public:   //member functions stored in public
    Animal();
    //if the parameters for domestic and predator are blank, it will automatically fill in false
    Animal(string name, bool domestic = false, bool predator = false);
    string getName() const; //values from these functions stay constant
    bool isDomestic() const;
    bool isPredator() const;
    void setName(string name);
    void setDomestic();
    void setPredator();
    friend bool operator==(const Animal& animalobj, const Animal& animalobj1); //check if teverything is the same all the way through
    void display();
  protected:      //private variables stored here
    string name_;
    bool domestic_;
    bool predator_;

};
