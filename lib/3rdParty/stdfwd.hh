#pragma once

#ifdef __APPLE__
	#include <vector>
	#include <map>
	#include <string>
	#include <iostream>
	#include <ostream>
	#include <istream>
	#include <set>
	#define STDFWD std
#else
	#include "stdfwd-orig.hh"
	#define STDFWD stdfwd
#endif

