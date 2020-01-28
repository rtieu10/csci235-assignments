#include "PostfixCalculator.hpp"
#include "PrecondViolatedExcep.hpp"
int main(){
  PostfixCalculator testcalc;
  std::string result;
  std::cout << testcalc.convertToPostfix("( 2 + 3 )") << std::endl;
  result = testcalc.convertToPostfix("3 - ( 137 + 76 )");
  std::cout << result << std::endl;
  std::cout << "----------------------------------------------" << std::endl;
  std::cout << testcalc.calculatePostfix("5 6 -") << std::endl;
  std::cout << testcalc.calculatePostfix("3 137 76 + -") << std::endl;
  std::cout << testcalc.calculatePostfix("5 3 + 2 *") << std::endl;
  testcalc.testCalculator("test.txt");
}
