# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
cmake_minimum_required(VERSION 3.5.1)
project( EnjoLibStat3rd )

include(../cmake/util.cmake)

option(WITH_FEATURE_ARRAY_FIRE 	"Use ArrayFire" OFF)
option(WITH_FEATURE_NEWMAT 	"Use NewMat"    OFF)
option(WITH_FEATURE_EIGEN 	"Use Eigen"     ON)
option(WITH_FEATURE_MKL 	"Use MKL"     	ON)
option(WITH_FEATURE_GSL 	"Use GSL"     	ON)

file( GLOB SRCS */*.cpp */*.h* Math/*/*.cpp */*/*.h*)
if (WITH_FEATURE_ARRAY_FIRE)
	find_package(ArrayFire REQUIRED)
	file( GLOB SRC_AF Statistical/3rdParty/CorrelationAF.* Statistical/3rdParty/RegressionAF.*)
	set( SRCS ${SRCS} ${SRC_AF} )
	set (EXTRA_LIBS ${EXTRA_LIBS} af)
endif()

if (WITH_FEATURE_NEWMAT)
	add_definitions("-DUSE_LIB_NEWMAT")
	include_directories("~/devel/lib/tree/include")
	link_directories("~/devel/lib/tree/lib")
	file( GLOB SRC_NM Statistical/3rdParty/EigenNewmat10.* )
	set( SRCS ${SRCS} ${SRC_NM} )
	set (EXTRA_LIBS ${EXTRA_LIBS} newmat)
endif()

if (WITH_FEATURE_EIGEN)
	find_package(Eigen3)
	include_directories(${EIGEN3_INCLUDE_DIRS})
		
	file( GLOB SRC_NM  Statistical/3rdParty/EigenEigen3.* Statistical/3rdParty/RegressionEigen.*)
	file( GLOB SRC_MKL Statistical/3rdParty/EigenMKL.* )
    	file( GLOB SRC_NP  Statistical/3rdParty/EigenNumpy.* )
	set( SRCS ${SRCS} ${SRC_NM} ${SRC_MKL} ${SRC_NP})
	#set (EXTRA_LIBS ${EXTRA_LIBS} eigen)
endif()

if (WITH_FEATURE_GSL)
	file( GLOB SRC_GSL Statistical/3rdParty/*GSL* Statistical/3rdParty/FFT.* Statistical/3rdParty/Gaussian.* Statistical/3rdParty/Wavelet.* )
	set( SRCS ${SRCS} ${SRC_GSL})
	set (EXTRA_LIBS ${EXTRA_LIBS} gsl gslcblas)
endif()

add_library (${PROJECT_NAME} ${LINK_TYPE} ${SRCS})
enjoSetupTarget(${PROJECT_NAME})

if (WITH_FEATURE_MKL)
	#find_package(MKL REQUIRED)
	set (ROOT_INCL "/usr/include")
	if(EXISTS "${ROOT_INCL}/mkl/mkl.h")
		include_directories("${ROOT_INCL}/mkl")
		link_directories("/usr/lib/x86_64-linux-gnu/mkl")
		target_compile_definitions(${PROJECT_NAME} PRIVATE EIGEN_USE_MKL_ALL=1 MKL_LP64=1)
#			MKL_DEBUG_CPU_TYPE=5
		target_link_libraries(${PROJECT_NAME} mkl_rt mkl_gnu_thread mkl_core gomp m dl)
		enjoMessage("Using MKL :) ")
	else()
	   # enjoWarning("===== MKL libs not found =====")
	    #enjoError("===== MKL libs not found =====")
	endif()
endif()

#target_link_libraries(${PROJECT_NAME} pthread ${EXTRA_LIBS})
target_link_libraries(${PROJECT_NAME} EnjoLib ${EXTRA_LIBS})
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

