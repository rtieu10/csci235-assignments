#pragma once
#include <iostream>
#include "Animal.hpp"
#include "ArrayBag.hpp"


class ZooRecord: public ArrayBag<Animal> {
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
