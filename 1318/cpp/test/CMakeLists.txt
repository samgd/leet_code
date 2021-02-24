add_executable(test_main test_main.cpp)
target_link_libraries(test_main CONAN_PKG::gtest)
target_include_directories(test_main PUBLIC "${PROJECT_SOURCE_DIR}/include")

include(GoogleTest)
gtest_discover_tests(test_main)
