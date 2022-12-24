# CMake generated Testfile for 
# Source directory: D:/CMakeProject
# Build directory: D:/CMakeProject/out/build/x64-Debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(gtest_tests "Tests/ctest-tests" "--gtest_output=xml:./ctest-tests.xml")
set_tests_properties(gtest_tests PROPERTIES  _BACKTRACE_TRIPLES "D:/CMakeProject/CMakeLists.txt;20;add_test;D:/CMakeProject/CMakeLists.txt;0;")
subdirs("external/googletest")
subdirs("CMakeProject")
subdirs("Matrix")
subdirs("Tests")
