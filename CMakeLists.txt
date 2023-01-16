cmake_minimum_required(VERSION 3.7)

project(easyPrint VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(easyPrint INTERFACE)
target_include_directories(easyPrint
                           INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                           $<INSTALL_INTERFACE:include>)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/easyPrintConfigVersion.cmake"
                                 VERSION 1.0 COMPATIBILITY AnyNewerVersion ARCH_INDEPENDENT)

install(TARGETS easyPrint EXPORT easyPrintTargets
        LIBRARY DESTINATION lib COMPONENT Runtime
        ARCHIVE DESTINATION lib COMPONENT Development
        RUNTIME DESTINATION bin COMPONENT Runtime
        PUBLIC_HEADER DESTINATION include COMPONENT Development
        BUNDLE DESTINATION bin COMPONENT Runtime)

include(CMakePackageConfigHelpers)
configure_package_config_file("${PROJECT_SOURCE_DIR}/cmake/easyPrintConfig.cmake.in"
                              "${PROJECT_BINARY_DIR}/easyPrintConfig.cmake"
                              INSTALL_DESTINATION lib/cmake/easyPrint)

install(EXPORT easyPrintTargets DESTINATION lib/cmake/easyPrint)
install(FILES "${PROJECT_BINARY_DIR}/easyPrintConfigVersion.cmake"
              "${PROJECT_BINARY_DIR}/easyPrintConfig.cmake"
        DESTINATION lib/cmake/easyPrint)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)

add_subdirectory(tests)
