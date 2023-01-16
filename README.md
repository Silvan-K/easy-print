# easyPrint: header-only library for printing variables and STL containers

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
