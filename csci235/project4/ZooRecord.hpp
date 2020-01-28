#pragma once
#include <string>
#include <iostream>
#include "List.hpp"
#include "Animal.hpp"
#include "Bird.hpp"
#include "Fish.hpp"
#include "Mammal.hpp"
#include "PrecondViolatedExcep.hpp"


class ZooRecord: public List<Animal*> {
public:
  ZooRecord();
  /**parameterized constructor
 @pre the input file is expected to be in CSV
 (comma separated value) format as:
 "animal_name,hair,feathers,eggs,milk,airborne,aquatic,predator,toothed,
 backbone,breathes,venomous,fins,legs,tail,domestic,catsize,class_type\n"
 @param input_file_name the name of the input file
 @post adds Animal objects to record as per the data in the input file
 **/
 ZooRecord(std::string input_file_name);
 /**@post displays all animals in record, one per line by calling animal's
display method” **/
 void display();

};
