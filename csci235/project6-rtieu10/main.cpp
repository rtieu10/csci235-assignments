#include "SortingComparison.hpp"

int main(){
SortingComparison Test(10);

std::cout << "RANDOM" << std::endl;
Test.runComparison(RANDOM);

std::cout << "DECREASING" << std::endl;
Test.runComparison(DECREASING);

std::cout << "INCREASING" << std::endl;
Test.runComparison(INCREASING);

}
