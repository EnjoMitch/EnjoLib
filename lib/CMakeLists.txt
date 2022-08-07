# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
cmake_minimum_required(VERSION 3.5.1)
project( EnjoLib )

include(../cmake/util.cmake)

file( GLOB SRCS */*.cpp */*.h* Math/*/*.cpp */*/*.h*)

add_library (${PROJECT_NAME} ${LINK_TYPE} ${SRCS})

if (NOT BUILD_MINGW)
	#set(EXTRA_LIBS crypto)
endif()

enjoSetupTarget(${PROJECT_NAME})


target_link_libraries(${PROJECT_NAME} pthread ${EXTRA_LIBS})
target_compile_options(${PROJECT_NAME} PUBLIC "-fPIC")
target_compile_options(${PROJECT_NAME} PUBLIC "-Werror=switch")
target_compile_options(${PROJECT_NAME} PUBLIC "-Werror=return-type")
if (USE_FLOATING_POINT_LOW_PRECISION)
	target_compile_options(${PROJECT_NAME} PUBLIC "-DEL_FLOATING_POINT_LOW_PRECISION")
endif()
if (NOT "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
	target_compile_options(${PROJECT_NAME} PUBLIC "-Werror=return-local-addr")
endif()


# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin/lib)

