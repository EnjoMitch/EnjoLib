cmake_minimum_required(VERSION 3.5.1)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
#find_package(Icecream)

#include(progs/cmake/BuildType.cmake)
include(util)
#include(cotire)
#include(PrecompiledHeader)

project (Enjo)
enable_testing()

option(BUILD_TESTS "Build Tests"   ON)
option(BUILD_GAMES "Build games"    ON)
option(BUILD_MDDC  "Build MDDClone" ON)
option(BUILD_WX    "Build WX basic"  ON)
option(BUILD_WX_APPS "Build WX apps"  ON)
option(BUILD_QT    "Build QT apps"  ON)
option(BUILD_CRYPT "Build Crypto"   OFF)

add_subdirectory(lib)
add_subdirectory(libBoost)
#add_subdirectory(progs/libPoco)



if (BUILD_WX)
#	add_subdirectory(progs/libwx)
#	add_subdirectory(progs/stock/wxConfQT)
#	if (BUILD_WX_APPS)
		#add_subdirectory(progs/wx/wxLanChat)
#		add_subdirectory(progs/wx/wxWyswietlaczZdjec)
#		add_subdirectory(progs/wx/mouse-sim)
#		add_subdirectory(progs/wx/Newsletter)
#	endif()
endif()

if (BUILD_TESTS)
	# Test load balancing
	# Sooner defined will start sooner
	add_subdirectory(tests/EnjoLibTest)
	add_subdirectory(tests/EnjoLibUTest)
endif()



