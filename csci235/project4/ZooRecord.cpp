#include "ZooRecord.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::endl;

//bool values outside so we can set them according to the string values
bool hair_value, airborne_value, aquatic_value, predator_value, toothed_value, venomous_value,fins_value, tail_value, domestic_value;
int legs1;
std::string animal_name;


  ZooRecord::ZooRecord(){
    item_count_ = 0; //0 items in the array bag
  }

  ZooRecord::ZooRecord(std::string input_file_name){
    std::ifstream fin(input_file_name.c_str());
    if (fin.fail()){
      std::cerr << "File cannot be opened for reading" << endl;
      exit(1);
    }

    std::string junk;
    std::string inputlines;

    getline(fin,junk);

//create string vars inside the while loop, while there are lines, the lines will be stored as strings in string variables
//ANIMAL NAME
  while(getline(fin, inputlines)){   //reads up to comma, parsing the data
    std::stringstream strstream(inputlines);  //line stored in strstream, and changes the normal line into strstream
    //string vars
    std::string stranimal_name,strhair,strairborne,straquatic,strpredator,strtoothed,strvenomous,strfins,strtail,strdomestic,strlegs,strclass_type;
    getline(strstream,stranimal_name, ','); //all stored in animal_name
    //std::cout << stranimal_name << std::endl;
    animal_name = stranimal_name;

//HAIR
    getline(strstream,strhair, ',');
    //std::cout <<strhair <<std::endl;
      if(strhair == "0"){ //if the string variable for hair = 0, it is false
        hair_value = false;
      }
      if(strhair == "1"){
        hair_value = true;
      }

    for(int i = 0; i < 3; i++){  //feathers, eggs, milk = junk
      getline(strstream, junk, ',');
    }

//AIRBORNE
  getline(strstream, strairborne, ',');
  //std::cout << strairborne << std::endl;
  if(strairborne == "0"){
    airborne_value = false;
  }
  if(strairborne == "1"){
    airborne_value = true;
  }

//AQUATIC
  getline(strstream,straquatic, ',');
  if(straquatic == "0"){
    aquatic_value = false;
  }
  if(straquatic == "1"){
    aquatic_value = true;
  }

//PREDATOR
  getline(strstream, strpredator,',');
  if(strpredator == "0"){
    predator_value = false;
  }
  if(strpredator == "1"){
    predator_value = true;
  }

//TOOTHED
  getline(strstream, strtoothed, ',');
  //std::cout << strtoothed << std::endl;
  if(strtoothed == "0"){
    toothed_value = false;
  }
  if(strtoothed == "1"){
    toothed_value = true;
  }

  for(int i = 0; i < 2; i++){
    getline(strstream, junk, ',');  //backbone & breathes = junk,
  }

//VENOMOUS
  getline(strstream,strvenomous, ',');
  if(strvenomous == "0"){
    venomous_value = false;
  }
  if(strvenomous == "1"){
    venomous_value = true;
  }

//FINS
  getline(strstream, strfins, ',');
    if(strfins == "0"){
      fins_value = false;
    }
    if(strfins == "1"){
      fins_value = true;
    }

//LEGS
  getline(strstream, strlegs,',');
    legs1 = stoi(strlegs);  //converts a string to an int

//TAIL
  getline(strstream, strtail, ',');
  if(strtail == "0"){
    tail_value = false;
  }
  if(strtail == "1"){
    tail_value = true;
  }

//DOMESTIC
  getline(strstream, strdomestic, ',');
  if(strdomestic == "0"){
    domestic_value = false;
  }
  if(strdomestic == "1"){
    domestic_value = true;
  }

  for(int i = 0; i < 1; i++){
    getline(strstream, junk, ','); //catsize = junk
  }

  getline(strstream, strclass_type, ',');

  if(strclass_type[0] == '1'){  //Mammal
    //creating a dynamically allocated Mammal obj
    Mammal *mammalobj = new Mammal(animal_name, domestic_value, predator_value); //creating mammal obj w paramters, name, dom, pred are already set
      if(hair_value){
        mammalobj->setHair();  //dynamically allocated object, so it dereferences pointer and calls the object
      }
      if(airborne_value){
        mammalobj->setAirborne();
      }
      if(aquatic_value){
        mammalobj->setAquatic();
      }
      if(toothed_value){              //if toothed_value = true
        mammalobj->setToothed();      //set toothed to true, accesses mammalobj and then access tooth var
      }
      if(fins_value){
        mammalobj->setFins();
      }
      if(tail_value){
        mammalobj->setTail();
      }

        mammalobj->setLegs(legs1);
        Animal *animal = mammalobj;
        insert(item_count_, animal);
    }


  if(strclass_type[0] == '2'){ //Bird
    Bird *birdobj= new Bird(animal_name, domestic_value, predator_value);

      if(airborne_value){
        birdobj->setAirborne();
      }
      if(aquatic_value){
        birdobj->setAquatic();
      }

      Animal *animal = birdobj;  //creating an animal object that has stores the bird object
      insert(item_count_, animal); //insert the animal pointer in the list!
  }

  if(strclass_type[0] == '4'){ //Fish
    Fish *fishobj = new Fish(animal_name, domestic_value, predator_value);

    if(venomous_value){
      fishobj->setVenomous();
    }

    Animal *animal = fishobj;
    insert(item_count_, animal);  //insert the animal pointer in the list!
  }

  }
  fin.close();
  }

  void ZooRecord::display(){   //displays each item
    for(int i = 0; i < item_count_; i++){
      getItem(i) -> display();  //dereferences the dynamically allocated items and calls the display function
  }
}
