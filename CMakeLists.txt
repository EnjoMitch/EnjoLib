cmake_minimum_required(VERSION 3.5.1)

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
#find_package(Icecream)

#include(progs/cmake/BuildType.cmake)
include(util)
#include(cotire)
#include(PrecompiledHeader)

project (Enjo)
enable_testing()

option(BUILD_EL_TESTS "Build Tests"   ON)
option(BUILD_BOOST "Build libBoost"  ON)
option(BUILD_WX    "Build WX basic"  ON)
option(BUILD_STAT_3RD    "Build statistical 3rd-party"  ON)

add_subdirectory(lib)
if (BUILD_BOOST)
	add_subdirectory(libBoost)
endif()
if (BUILD_STAT_3RD)
	add_subdirectory(libStat3rd)
endif()
#add_subdirectory(progs/libPoco)



if (BUILD_WX)
	add_subdirectory(libwx)
#	if (BUILD_WX_APPS)
		#add_subdirectory(progs/wx/wxLanChat)
#		add_subdirectory(progs/wx/wxWyswietlaczZdjec)
#		add_subdirectory(progs/wx/mouse-sim)
#		add_subdirectory(progs/wx/Newsletter)
#	endif()
endif()

if (BUILD_EL_TESTS)
	# Test load balancing
	# Sooner defined will start sooner
	add_subdirectory(tests/EnjoLibAnimTest)
	add_subdirectory(tests/EnjoLibPerfTest)
	add_subdirectory(tests/EnjoLibTest)
  add_subdirectory(tests/EnjoLibUTest)
endif()



