#####################################################################################################################

# Jorge Agramunt Ros    @ IFIC(Valencia,Spain)  jorge.agramunt@ific.uv.es
# Alvaro Tolosa Delgado @ IFIC(Valencia,Spain)  alvaro.tolosa@ific.uv.es
# Copyright (c) 2016 Jorge Agramunt & Alvaro Tolosa. All rights reserved.

#####################################################################################################################

# Example adapted from https://root.cern.ch/faq/can-i-integrate-root-my-cmake-build

#####################################################################################################################



# CMakeLists.txt for event package. It creates a library with dictionary and a main program
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(customTreeExample)

# You need to tell CMake where to find the ROOT installation. This can be done in a number of ways:
#   - ROOT built with classic configure/make use the provided $ROOTSYS/etc/cmake/FindROOT.cmake
#   - ROOT built with CMake. Add in CMAKE_PREFIX_PATH the installation prefix for ROOT
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS MathCore RIO Hist Tree Net Graf3d Graf Gpad Thread TreePlayer)

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
add_definitions(${ROOT_CXX_FLAGS}  )
ROOT_GENERATE_DICTIONARY(G__data2Tree data2Tree.hpp LINKDEF data2TreeLinkDef.hpp)

#---Create a shared library with geneated dictionary
add_library(data2TreeLib SHARED data2Tree.cxx G__data2Tree.cxx)
target_link_libraries(data2TreeLib ${ROOT_LIBRARIES}  ) 

#---Create  a main program using the library
add_executable(treeExample main.cpp)
target_link_libraries(treeExample ${ROOT_LIBRARIES} data2TreeLib)

# C++11
#set_property(TARGET treeExample PROPERTY CXX_STANDARD 11)
#set_property(TARGET treeExample PROPERTY CXX_STANDARD_REQUIRED ON)
# PIC
set_property(TARGET treeExample PROPERTY POSITION_INDEPENDENT_CODE ON)
