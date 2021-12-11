# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
cmake_minimum_required(VERSION 3.5.1)
include(../cmake/util.cmake)
project( wx )

set (WX_COMPS "core base")
#message(FATAL_ERROR "${CMAKE_CURRENT_SOURCE_DIR}")
if (BUILD_MINGW)
else()
	if (WIN32)
		message(STATUS "Config wx for Windows")
		set(wxWidgets_EXCLUDE_COMMON_LIBRARIES TRUE)
	endif()
	find_package(wxWidgets COMPONENTS ${WX_COMPS} REQUIRED)
	include(${wxWidgets_USE_FILE})
	#message(FATAL_ERROR ${wxWidgets_USE_FILE})
endif()


file( GLOB SRCS src/*.cpp src/*.h* src/*/*.cpp src/*/*.h*)


add_library(${PROJECT_NAME} ${LINK_TYPE} ${SRCS})
enjoSetupTarget(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} EnjoLib ${wxWidgets_LIBRARIES})

enjo_target_pch(${PROJECT_NAME} src/pch/wx_pch.h)
enjo_target_unity(${PROJECT_NAME})

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin/lib)
SetupCotire(${PROJECT_NAME})

