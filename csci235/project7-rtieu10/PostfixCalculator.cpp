#include "PostfixCalculator.hpp"
#include "PrecondViolatedExcep.hpp"

PostfixCalculator::PostfixCalculator(){

}

std::string PostfixCalculator::convertToPostfix(std::string infix_expression){
  std::stack<char> mystack;
  std::string postfixexp = "";
  std::string stream;                  //string var which each line will be stored in
  std::stringstream ss(infix_expression);  //names the stream ss and takes in infix_expression
  while(getline(ss, stream, ' ')){     //splits by spaces
      char ch = stream[0];     //sets it equal to the first thing in the stream
      if(ch >= '0' && ch <= '9'){      //if the char we are looking at is a num
        postfixexp += stream;
        postfixexp += " ";

      }
    else if(ch == '('){
      mystack.push(ch);
    }
    else if(precedence(ch) >= 1){   //if it is an operator

      while(!mystack.empty() && mystack.top() != '(' && precedence(ch) <= precedence(mystack.top())){
        postfixexp += mystack.top();
        postfixexp += " ";
        mystack.pop();
      }
      mystack.push(ch);
    }
    else if(ch == ')'){
      while(!mystack.empty() && mystack.top() != '('){
        postfixexp += mystack.top();
        postfixexp += " ";
        mystack.pop();
      }
      if(mystack.empty()){
        throw(PrecondViolatedExcep("Unbalanced parenthesis"));
      }
      mystack.pop();
    }
    else {
      throw(PrecondViolatedExcep("Unknown operator"));
    }
  }
  while(!mystack.empty()){
    if(mystack.top() == '('){
      throw(PrecondViolatedExcep("Unbalanced parenthesis"));
    }
    postfixexp += mystack.top();  //adds everything on the stack to the postfixexp
    postfixexp += " ";
    mystack.pop();
  }
  return postfixexp;
}


int PostfixCalculator::precedence(char oper){
  if(oper == '*' || oper == '/'){
    return 2;
  }
  else if(oper == '+' || oper == '-'){
    return 1;
  }
    return 0;
}

double PostfixCalculator::calculatePostfix(std::string postfix_expression){

   std::string numbers = "";
   std::stack<double> numstack;
   double stacktop;
   double stacktop1;
   char postchar;
   double nums = 0.0;
   for(int i = 0; i < postfix_expression.length(); i++){
    if(postfix_expression[i] >= '0' && postfix_expression[i] <= '9'){
      while(i < postfix_expression.length() && postfix_expression[i] >= '0' && postfix_expression[i] <= '9'){
        numbers += postfix_expression[i];   //adding all digits to the string numbers
        nums = std::stod(numbers);          //convert to double
        i++;   //increment i, so we dont leave the loop
      }
    numstack.push(nums);   //pushing all the numbers to the stack, stod to convert the char to a double
    numbers = "";  //resetting string to empty, so we don't consistently add to the string and push it
    }
    if(!numstack.empty() && precedence(postfix_expression[i]) >= 1){   //if the stack is not empty, and we see an operator
      stacktop = numstack.top();       // take the number on the top and store it
      numstack.pop();
      stacktop1 = numstack.top();
      numstack.pop();
      numstack.push(calculate(postfix_expression[i], stacktop1, stacktop));  //call the calculate function
    }
  }
  return numstack.top();
}

double PostfixCalculator::calculate(char oper, double num1, double num2){
  double result = 0.0;
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
  std::string input;
  std::string output;
  std::string result;
  std::ifstream fin(input_file_name.c_str());
  std::ofstream out;
  std::ofstream resultfile;
  out.open("postfix.txt");    //by "opening" the file we are creating it
  resultfile.open("results.txt");
  while(getline(fin, input)){   //reads line from txt file
    try{
      output = convertToPostfix(input);      //calls converttoPostfix, and then sets equal to output
      out << output;                         //writes the result into an output stream called out
      out << std::endl;
      auto result = calculatePostfix(output);    //calculates the line we are inputting
      resultfile << result;             //writes into the file
      resultfile << std::endl;
    }
    catch(PrecondViolatedExcep x){
      out << x.what();
      out << std::endl;
      resultfile << x.what();
      resultfile << std::endl;
    }
  }
  out.close();
  resultfile.close();
  fin.close();
}
