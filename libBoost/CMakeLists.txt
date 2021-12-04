# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
cmake_minimum_required(VERSION 3.5.1)
project( EnjoLibBoost )

include(../cmake/util.cmake)

file( GLOB SRCS ${PROJECT_NAME}/*.cpp */*.h */*.hpp)
add_library (${PROJECT_NAME} ${LINK_TYPE} ${SRCS})

find_package(Boost QUIET REQUIRED COMPONENTS system filesystem iostreams date_time serialization program_options atomic) 

#target_link_libraries(${PROJECT_NAME} boost_filesystem boost_system boost_iostreams boost_atomic boost_serialization)
target_link_libraries(${PROJECT_NAME} ${Boost_SYSTEM_LIBRARY}_filesystem ${Boost_SYSTEM_LIBRARY}_system ${Boost_SYSTEM_LIBRARY}_iostreams ${Boost_SYSTEM_LIBRARY}_serialization ${Boost_SYSTEM_LIBRARY}_program_options ${Boost_SYSTEM_LIBRARY}_atomic ${Boost_SYSTEM_LIBRARY}_date_time
EnjoLib # TODO: Should be EnjoLibTypes in the end
) # boost_atomic)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin/lib)
SetupCotire(${PROJECT_NAME})
