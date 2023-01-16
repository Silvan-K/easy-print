add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE easyPrint)
enable_testing()
add_test(NAME tests COMMAND $<TARGET_FILE:tests>)
