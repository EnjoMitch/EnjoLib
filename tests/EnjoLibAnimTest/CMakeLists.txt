# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
cmake_minimum_required(VERSION 3.5.1)
include(../../cmake/util.cmake)
project(EnjoLibAnimTest)

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib")

file( GLOB SRCS src/*.cpp */*.h */*.hpp)

#link_directories("~/devel/lib/tree/lib")
add_executable(${PROJECT_NAME} ${SRCS})
# add_test(${PROJECT_NAME} ${PROJECT_NAME}) This shouldn't be executed automatically as it requires time and user supervision
enjoSetupTarget(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} EnjoLib)
#enjo_target_pch(${PROJECT_NAME} src/pch_test.h) # Non existant yet
enjo_target_unity(${PROJECT_NAME})

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

