//
//  CodewordGenerator.cpp
//  CodewordGenerator
//
//  Created by Rachel Tieu on 12/1/19.
//  Course project, Hunter Collegge, CSci 235 - Software Design and Analysis II
//
// ********** ADD YOUR CONTRIBUTION INFORMATION HERE!!! ******************



#include "CodewordGenerator.hpp"
#include <regex>

CodewordGenerator::CodewordGenerator(){
}

/**
 @post this function generates a matching code word
 @param a string that is a pattern
 @return the codeword
 */

std::string CodewordGenerator::generateShortestWord(std::string pattern){
  std::string empty_string = "";
  std::vector<char> alph;
  std::string current_string;
  std::queue<std::string> myqueue;
  std::regex test(pattern);
  for (int i = 'A'; i <= 'Z'; i++){      //adding letters to vector
    alph.push_back(i);
  }
  myqueue.push(empty_string);
  while(!myqueue.empty()){
    current_string = myqueue.front();          //sets current to the front of the queue
    myqueue.pop();
    if(!std::regex_match(current_string,test)){
      for(int i = 0; i < alph.size(); i++){
        myqueue.push(current_string + alph[i]);      //push the string to the queue, and diff letter with every iteration
      }
    }
    else{
      return current_string;
    }
  }
  return "";
}

/**
 @post a function that generates a pattern of a certain length
 @param takes a pattern string, and an integer variable
 @param that specifies the string length
 @return the codeword

 */

std::string CodewordGenerator::generateLengthWord(std::string pattern, int length){
  std::stack <std::string> mystack;
  std::string empty_string ="";
  std::vector<char> alph;
  std::string current_string;
  std::regex test(pattern);
  for(int i = 'A'; i <= 'Z'; i++){       //creates a vector of letters
    alph.push_back(i);
  }
  mystack.push(empty_string);           //push empty string to stack
  while(!mystack.empty()){
    current_string = mystack.top();
    mystack.pop();                      //pops empty string off stack
    if(!std::regex_match(current_string, test) && current_string.length() < length){
      for(int i = 0; i < alph.size(); i++){
        mystack.push(current_string + alph[i]);         //adding the string and a diff letter with each iteration
      }
    }
    else if(std::regex_match(current_string, test) && current_string.length() == length){
      return current_string;
    }
  }
  return "";
}
