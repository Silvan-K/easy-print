cmake_minimum_required(VERSION 3.7)

project(debug_vars VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(debug_vars INTERFACE)
target_include_directories(debug_vars
                           INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                           $<INSTALL_INTERFACE:include>)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/debug_varsConfigVersion.cmake"
                                 VERSION 1.0 COMPATIBILITY AnyNewerVersion ARCH_INDEPENDENT)

install(TARGETS debug_vars EXPORT debug_varsTargets
        LIBRARY DESTINATION lib COMPONENT Runtime
        ARCHIVE DESTINATION lib COMPONENT Development
        RUNTIME DESTINATION bin COMPONENT Runtime
        PUBLIC_HEADER DESTINATION include COMPONENT Development
        BUNDLE DESTINATION bin COMPONENT Runtime)

include(CMakePackageConfigHelpers)
configure_package_config_file("${PROJECT_SOURCE_DIR}/cmake/debug_varsConfig.cmake.in"
                              "${PROJECT_BINARY_DIR}/debug_varsConfig.cmake"
                              INSTALL_DESTINATION lib/cmake/debug_vars)

install(EXPORT debug_varsTargets DESTINATION lib/cmake/debug_vars)
install(FILES "${PROJECT_BINARY_DIR}/debug_varsConfigVersion.cmake"
              "${PROJECT_BINARY_DIR}/debug_varsConfig.cmake"
        DESTINATION lib/cmake/debug_vars)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)

add_subdirectory(tests)
