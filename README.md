# easyPrint: header-only printing library

Provides a simple function that allows the user to conveniently print variables and STL containers without explicitly looping over them. Designed to behave similarly to python's print function. 

## Build, test, and install

To install this project under the `$PREFIX` (`$HOME/.local/`, for example):

```
# Clone repo
git@github.com:Silvan-K/easy-print.git && cd easy-print

# Configure build
mkdir build && cd build && cmake ../

# Build, install, test
cmake --build .
cmake --install .
ctest --test-dir tests
```
The above commands install the header [easyPrint.hpp](https://github.com/Silvan-K/easy-print/blob/master/include/easyPrint.hpp) in `$PREFIX/include/`.

## Using the library

To use this library in a hypothetical cmake target `MyTarget`, please add the following lines to your cmake file:

```
find_package(easyPrint CONFIG REQUIRED)
target_link_libraries(MyTarget easyPrint)
```

This sets the required include path to easyPrint automatically. In your code for `MyTarget`, you can then use the library as follows:

``` 
#include "easyPrint.hpp"
#include <vector>
#include <array>

std::vector<std::vector<int>> nested_vec{std::vector<int>{1,2,3,4},
                                         std::vector<int>{5,6,7}};

easyPrint::print("Some vector", std::vector<int>{1,2,3},
                 "followed by an int", 12,
                 "and another vector", std::vector<double>(3,12.0),
                 "and a nested vector", nested_vec,
                 "and an empty vector", std::vector<double>(),
                 "and an array", std::array<double, 3>());
                 
easyPrint::printErr(12, "<- this number will end up in stderr");
```
