# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
cmake_minimum_required(VERSION 3.5.1)
include(../../cmake/util.cmake)
project(EnjoLibUTest)
enable_testing()
find_package(UnitTest++)

file( GLOB SRCS src/*.cpp */*.h */*.hpp)

add_executable(${PROJECT_NAME} ${SRCS})
add_test(${PROJECT_NAME} ${PROJECT_NAME})
enjoSetupTarget(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC ${UTPP_INCLUDE_DIRS})
if (APPLE)
	# Workaround for brew not providing CMake module
	target_link_directories(${PROJECT_NAME} PUBLIC /usr/local/opt/unittest-cpp/lib)
endif()
target_link_libraries(${PROJECT_NAME} EnjoLibStat3rd UnitTest++)
enjo_target_pch(${PROJECT_NAME} src/pch_test.h)
enjo_target_unity(${PROJECT_NAME})

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

