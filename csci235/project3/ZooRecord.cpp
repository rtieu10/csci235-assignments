#include "ZooRecord.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;


  ZooRecord::ZooRecord(){
    item_count_ = 0; //0 items in the array bag
  }

  ZooRecord::ZooRecord(std::string input_file_name){
    std::ifstream fin(input_file_name.c_str());
    if (fin.fail()){
      std::cerr << "File cannot be opened for reading" << endl;
      exit(1);
    }

    string junk;
    string inputlines;

    getline(fin,junk);

  while(getline(fin, inputlines)){   //reads up to comma, parsing the data
    string animal_name;  //storing the values from csv file (that arent junk)
    bool predator;
    bool domestic;

    std::stringstream strstream(inputlines);  //line stored in strstream, and changes the normal line into strstream 
    string animal_name1;
    string strpredator;
    string strdomestic;
    getline(strstream, animal_name1, ',');
    animal_name = animal_name1;   //store all the names in the csv to animal_name

    for(int i = 0; i < 6; i++){ //looping through the titles of each columns btwn name & predator
      getline(strstream, junk, ',');  //will loop through and set everything inbetween to junk and stop at every comma
    }

//PREDATOR
    getline(strstream, strpredator, ',');  //gets the lines and stores it in str predator

    if(strpredator == "1"){ //check the string value, and setting bool
      predator = true;
    }

    if(strpredator == "0"){
      predator = false;
    }

    for(int i = 0; i < 7; i++){
      getline(strstream, junk, ',');
    }

//DOMESTIC
    getline(strstream, strdomestic, ',');
    if(strdomestic == "1"){
      domestic = true;
    }

    if(strdomestic == "0"){
      domestic = false;
    }

    getline(strstream, junk, ',');  //set everything after to junk
    Animal object(animal_name,domestic,predator);
    add(object);  //adding animal object to the items array

  }
  fin.close();
  }

  void ZooRecord::display(){   //displays each item
    for(int i = 0; i < item_count_; i++){
      items_[i].display();
  }
}
