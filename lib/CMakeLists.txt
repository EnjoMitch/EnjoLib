# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
cmake_minimum_required(VERSION 3.5.1)
project( EnjoLib )

include(../cmake/util.cmake)

file( GLOB SRCS */*.cpp */*.h* Math/*/*.cpp */*/*.h*)

option (WITH_FEATURE_EIGEN "Eigen" ON)
if (WITH_FEATURE_EIGEN)
	find_package(Eigen3)
	include_directories(${EIGEN3_INCLUDE_DIRS})
	
	
	
	file( GLOB SRC_NM  Statistical/3rdParty/EigenEigen3.* )
	file( GLOB SRC_MKL Statistical/3rdParty/EigenMKL.* )
    	file( GLOB SRC_NP  Statistical/3rdParty/EigenNumpy.* )
	set( SRCS ${SRCS} ${SRC_NM} ${SRC_MKL} ${SRC_NP})
endif()

add_library (${PROJECT_NAME} ${LINK_TYPE} ${SRCS})

target_link_libraries(${PROJECT_NAME} crypto pthread ${EXTRA_LIBS})
target_compile_options(${PROJECT_NAME} PUBLIC "-fPIC")
target_compile_options(${PROJECT_NAME} PUBLIC "-Werror=switch")
target_compile_options(${PROJECT_NAME} PUBLIC "-Werror=return-type")
if (NOT "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
	target_compile_options(${PROJECT_NAME} PUBLIC "-Werror=return-local-addr")
endif()



# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin/lib)

