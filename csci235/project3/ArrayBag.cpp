//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

//  Modified by Tiziana Ligorio for CSCI 235 Hunter college 2019

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.hpp"

/** default constructor**/
template<class T>
ArrayBag<T>::ArrayBag(): item_count_(0) //initializes item count to 0
{
}  // end default constructor


/**
 @return item_count_ : the current size of the bag
 **/
template<class T>
int ArrayBag<T>::getCurrentSize() const
{
	return item_count_;
}  // end getCurrentSize


/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class T>
bool ArrayBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty


/**
 @return true if new_etry was successfully added to items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::add(const T& new_entry)
{

	if(getFrequencyOf(new_entry)==0){
		bool has_room = (item_count_ < DEFAULT_CAPACITY);
		if (has_room)
		{
			items_[item_count_] = new_entry;
			item_count_++;
	        return true;
		}  // end if
	}

	return false;
}  // end add


/**
 @return true if an_etry was successfully removed from items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::remove(const T& an_entry)
{
   int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}  // end if

	return can_remove;
}  // end remove


/**
 @post item_count_ == 0
 **/
template<class T>
void ArrayBag<T>::clear()
{
	item_count_ = 0;
}  // end clear


/**
 @return the number of times an_entry is found in items_
 **/
template<class T>
int ArrayBag<T>::getFrequencyOf(const T& an_entry) const
{
   int frequency = 0;
   int cun_index = 0;       // Current array index
   while (cun_index < item_count_)
   {
      if (items_[cun_index] == an_entry)
      {
         frequency++;
      }  // end if

      cun_index++;          // Increment to next entry
   }  // end while

   return frequency;
}  // end getFrequencyOf


/**
 @return true if an_etry is found in items_, false otherwise
 **/
template<class T>
bool ArrayBag<T>::contains(const T& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}  // end contains


/**
 @return a vector having the same cotntents as items_
 **/
template<class T>
std::vector<T> ArrayBag<T>::toVector() const
{
   std::vector<T> bag_contents;
	for (int i = 0; i < item_count_; i++)
		bag_contents.push_back(items_[i]);

   return bag_contents;
}  // end toVector





// ********* PRIVATE METHODS **************//

/**
 @param target to be found in items_
 @return either the index target in the array items_ or -1,
 if the array does not containthe target.
 **/
template<class T>
int ArrayBag<T>::getIndexOf(const T& target) const
{
	bool found = false;
   int result = -1;
   int search_index = 0;

   // If the bag is empty, item_count_ is zero, so loop is skipped
   while (!found && (search_index < item_count_))
   {
      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      }
      else
      {
         search_index++;
      }  // end if
   }  // end while

   return result;
}  // end getIndexOf

template<class T>
void ArrayBag<T>::display() const{
	for(int i=0; i < item_count_; i++){
		if (i < item_count_ - 1){        //prints out all the items od less than index i
			std::cout << items_[i] << ",";
		}
		else{
			std::cout << items_[i] << std::endl;
		}
	}

}


template<class T>
void ArrayBag<T>::operator+=(const ArrayBag<T>& a_bag){ //adding elements to parameter a_bag
	for(int i = 0; i < a_bag.getCurrentSize(); i++){
		add(a_bag.items_[i]); //a_bag.items,we are referring back to the array called items_ in the .hpp
	}
}

template<class T>
void ArrayBag<T>::operator-=(const ArrayBag<T>& a_bag){
	for(int i = 0; i < a_bag.getCurrentSize(); i++){
		remove(a_bag.items_[i]);
	}
}

template<class T>
void ArrayBag<T>::operator /=(const ArrayBag<T>& a_bag){  //intersection
	for(int i = 0; i < a_bag.getCurrentSize(); i++){
		if(!a_bag.contains(items_[i])){   //the a bag does not caontain the item, then remove it
			remove(items_[i]);    //refer to items_[i] because we are only referring to the items and not the bag
		}
	}
}
