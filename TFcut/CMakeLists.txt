# CMakeLists.txt for the TFCut.so libraries and droot
# based on
# CMakeLists.txt for the ROOT test programs. 
# This shows nicely how to compile and link applications
# using the ROOT libraries on all supported platforms.
#
# Author: Pere Mato, 25/10/2010
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(TFcut)

# 

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

find_package(ROOT REQUIRED)

if(CMAKE_SYSTEM_NAME MATCHES Darwin)
  # To avoid to set ld_Library_path to locate the test libraries
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,@loader_path/.")
endif()

# 

include(${ROOT_USE_FILE})

#---event------------------------------------------------------------------------------------- 
ROOT_GENERATE_DICTIONARY(TFcutDict ${CMAKE_CURRENT_SOURCE_DIR}/TFWcut.h ${CMAKE_CURRENT_SOURCE_DIR}/TFLcut.h MODULE TFcut LINKDEF EventLinkDef.h)
ROOT_LINKER_LIBRARY(TFcut TFWcut.C TFLcut.C TFcutDict.cxx LIBRARIES)

