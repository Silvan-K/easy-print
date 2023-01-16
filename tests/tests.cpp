#include "debug_vars.hpp"
#include <vector>
#include <array>

int main(int argc, char** argv) {

  std::vector<std::vector<int>> nested_vec{std::vector<int>{1,2,3,4},
                                           std::vector<int>{5,6,7}  };

  
  easyPrint::print(12, "<- this is an integer");
  
  easyPrint::printErr(12, "<- this number will end up in stderr");

  easyPrint::print("Some vector", std::vector<int>{1,2,3},
		   "followed by an int", 12,
		   "and another vector", std::vector<double>(3,12.0),
		   "and a nested vector", nested_vec,
		   "and an empty vector", std::vector<double>(),
		   "and an array", std::array<double, 3>());
  
}
