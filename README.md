# easyPrint: a header-only library for printing variables and STL containers

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