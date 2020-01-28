#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>
#include <sstream>
#include <fstream>
#include <cstdlib> 

class PostfixCalculator{
public:
  PostfixCalculator();

  /*Takes a string representation of the infix expression, parses it into the
  corresponding postfix expression and returns the postfix expression as a string. */
  std::string convertToPostfix(std::string infix_expression);

  /*takes a string representation of the postfix expression (in the format described
above), calculates the result and returns it. It assumes that the postfix expression is
well formed (don’t forget to specify all pre and post conditions as well s inputs and
outputs in your comment preambles) */
  double calculatePostfix(std::string postfix_expression);


  /*for every infix expression from input file:
    Convert to Postfix
    write the postfix expression, but if there is an exception write the error message
    look through the postfix expression, if it is well formed write the result in result.txt */
  void testCalculator(std::string input_file_name);
private:
  //if it takes precedence return 2, else return 1
  int precedence(char oper);
  double calculate(char oper, double num1, double num2);
};
