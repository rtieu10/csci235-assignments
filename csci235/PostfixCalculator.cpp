#include "PostfixCalculator.hpp"

PostfixCalculator::PostfixCalculator(){

}

std::string PostfixCalculator::convertToPostfix(std::string infix_expression){
  std::stack<char> mystack;
  std::string postfixexp = "";
  //char infchar
  for(int i = 0; i < infix_expression.length(); i++){
    //switch(infix_expression[i]){
    //infchar = infix_expression[i];
      if(isdigit(infix_expression[i])){        //if the char we are looking at is a num
        if(i > 0){
          if(isdigit(infix_expression[i-1])){   //if the char before is a num
            postfixexp = postfixexp.substr(0,postfixexp.length()-1);
          //postfixexp += infchar;                  //add the char we are currently at to the string
          //postfixexp += " ";
          //std::cout << "hi" << std::endl;
          }
        }
        postfixexp += infix_expression[i];
        postfixexp += " ";

      }
    else if(infix_expression[i] == '('){
      mystack.push(infix_expression[i]);
    }
    else if(infix_expression[i] == '+' || infix_expression[i] == '-' || infix_expression[i] == '*' || infix_expression[i] == '/'){
      while(!mystack.empty() && mystack.top() != '(' && precedence(infix_expression[i]) < precedence(mystack.top())){
        postfixexp += mystack.top();
        postfixexp += ' ';
        mystack.pop();
      }
      mystack.push(infix_expression[i]);
    }
    else if(infix_expression[i] == ')'){
      while(mystack.top() != '('){
        postfixexp += mystack.top();
        postfixexp += ' ';
        mystack.pop();
      }
      mystack.pop();
    }
    else if(infix_expression[i] != ' '){
      return "Precondition Violated Exception: Unknown operator";
    }
  }
  while(!mystack.empty()){
    postfixexp += mystack.top();  //adds everything on the stack to the postfixexp
    postfixexp += ' ';
    mystack.pop();
  }
  std::cout << postfixexp << std::endl;
  for(int i = 0; i < postfixexp.length(); i++){
    //std::cout << "hi" << std::endl;
    if(postfixexp[i] == '(' || postfixexp[i] == ')'){
      return "Precondition Violated Exception: Unbalanced parenthesis";  //if the postfix expression has parentheses then print out this error message
    }
  }
  return postfixexp;
}


int PostfixCalculator::precedence(char oper){
  int val;
  if(oper == '*' || oper == '/'){
    val = 2;
  }
  else{
    val = 1;
  }
  return val;
}

double PostfixCalculator::calculatePostfix(std::string postfix_expression){
  std::stack<double> numstack;
  std::string numbers = "";
  double stacktop;
  double stacktop1;
  char postchar;
  double nums;
  for(int i = 0; i < postfix_expression.length(); i++){   //loop through the string that we passed through
    //postchar = postfix_expression[i];
    if(isdigit(postfix_expression[i])){
      while(isdigit(postfix_expression[i])){
        numbers += postfix_expression[i];   //adding all gigits to the string numbers
        i++;   //increment i, because we don't want it to leave the while loop until we have all the numbers
      }
      nums = std::stod(numbers);
      numstack.push(nums);   //pushing all the numbers to the stack, stod to convert the char to a double
      numbers = "";  //resetting string to empty, so we don't consistently add to the string and push it
    }
    if(postfix_expression[i] == '+' || postfix_expression[i] == '-' || postfix_expression[i] == '*' || postfix_expression[i] == '/'){
      stacktop = numstack.top();
      numstack.pop();
      stacktop1 = numstack.top();
      numstack.pop();
      numstack.push(calculate(postfix_expression[i], stacktop, stacktop1));
    }
  }
  return numstack.top();
}

double PostfixCalculator::calculate(char oper, double num1, double num2){
  double result;
  if(oper == '+'){
    result = num1 + num2;
  }
  else if(oper == '-'){
    result = num1 - num2;
  }
  else if(oper == '*'){
    result = num1 * num2;
  }
  else{
    result = num1/num2;
  }
  return result;
}

void PostfixCalculator::testCalculator(std::string input_file_name){

}
