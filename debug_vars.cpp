#include "debug_vars.hpp"

int main(int argc, char** argv) {

  std::vector<std::vector<int>> nested_vec{std::vector<int>{1,2,3,4},
                                           std::vector<int>{5,6,7}  };

  DEBUG_VARS(12, "<- this is an integer");

  DEBUG_VARS("Some vector", std::vector<int>{1,2,3},
	     "followed by an int", 12,
	     "and another vector", std::vector<double>(3,12.0),
	     "and a nested vector", nested_vec);
  
}