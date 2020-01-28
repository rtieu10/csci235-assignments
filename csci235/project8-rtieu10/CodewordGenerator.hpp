#ifndef CODEWORD_GENERATOR_
#define CODEWORD_GENERATOR_
#include <iostream>
#include <regex>
#include <string>
#include <queue>
#include <stack>
#include <vector>

class CodewordGenerator{
public:
  CodewordGenerator(); 
  /*takes a string pattern and returns the shortest string that matches the pattern
exploring the space of possible alphabet permutations in Breadth First Search
order.*/
  std::string generateShortestWord(std::string pattern);

  /*takes a string pattern and an integer n and returns a string of length n that
matches the pattern exploring the space of possible alphabet permutations in
Depth First Search order.*/
  std::string generateLengthWord(std::string pattern, int length);


};


#endif
