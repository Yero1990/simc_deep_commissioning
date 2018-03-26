# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.7.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.7.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/boeglin.1/HallA/analysis/TFcut.so

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/boeglin.1/HallA/analysis/TFcut.so/build

# Include any dependencies generated for this target.
include CMakeFiles/TFcut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TFcut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TFcut.dir/flags.make

TFcutDict.cxx: ../EventLinkDef.h
TFcutDict.cxx: ../TFWcut.h
TFcutDict.cxx: ../TFLcut.h
TFcutDict.cxx: ../TFWcut.h
TFcutDict.cxx: ../TFLcut.h
TFcutDict.cxx: ../EventLinkDef.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/data/boeglin.1/HallA/analysis/TFcut.so/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating TFcutDict.cxx, libTFcut_rdict.pcm, libTFcut.rootmap"
	/data/boeglin.1/root_versions/root_6.10.08/bin/rootcling -f TFcutDict.cxx -s /data/boeglin.1/HallA/analysis/TFcut.so/build/libTFcut.dylib -rml libTFcut.dylib -rmf /data/boeglin.1/HallA/analysis/TFcut.so/build/libTFcut.rootmap -I/data/boeglin.1/root_versions/root_6.10.08/include /data/boeglin.1/HallA/analysis/TFcut.so/TFWcut.h /data/boeglin.1/HallA/analysis/TFcut.so/TFLcut.h /data/boeglin.1/HallA/analysis/TFcut.so/EventLinkDef.h

libTFcut_rdict.pcm: TFcutDict.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate libTFcut_rdict.pcm

libTFcut.rootmap: TFcutDict.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate libTFcut.rootmap

CMakeFiles/TFcut.dir/TFWcut.C.o: CMakeFiles/TFcut.dir/flags.make
CMakeFiles/TFcut.dir/TFWcut.C.o: ../TFWcut.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/boeglin.1/HallA/analysis/TFcut.so/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TFcut.dir/TFWcut.C.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TFcut.dir/TFWcut.C.o -c /data/boeglin.1/HallA/analysis/TFcut.so/TFWcut.C

CMakeFiles/TFcut.dir/TFWcut.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TFcut.dir/TFWcut.C.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/boeglin.1/HallA/analysis/TFcut.so/TFWcut.C > CMakeFiles/TFcut.dir/TFWcut.C.i

CMakeFiles/TFcut.dir/TFWcut.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TFcut.dir/TFWcut.C.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/boeglin.1/HallA/analysis/TFcut.so/TFWcut.C -o CMakeFiles/TFcut.dir/TFWcut.C.s

CMakeFiles/TFcut.dir/TFWcut.C.o.requires:

.PHONY : CMakeFiles/TFcut.dir/TFWcut.C.o.requires

CMakeFiles/TFcut.dir/TFWcut.C.o.provides: CMakeFiles/TFcut.dir/TFWcut.C.o.requires
	$(MAKE) -f CMakeFiles/TFcut.dir/build.make CMakeFiles/TFcut.dir/TFWcut.C.o.provides.build
.PHONY : CMakeFiles/TFcut.dir/TFWcut.C.o.provides

CMakeFiles/TFcut.dir/TFWcut.C.o.provides.build: CMakeFiles/TFcut.dir/TFWcut.C.o


CMakeFiles/TFcut.dir/TFLcut.C.o: CMakeFiles/TFcut.dir/flags.make
CMakeFiles/TFcut.dir/TFLcut.C.o: ../TFLcut.C
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/boeglin.1/HallA/analysis/TFcut.so/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TFcut.dir/TFLcut.C.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TFcut.dir/TFLcut.C.o -c /data/boeglin.1/HallA/analysis/TFcut.so/TFLcut.C

CMakeFiles/TFcut.dir/TFLcut.C.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TFcut.dir/TFLcut.C.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/boeglin.1/HallA/analysis/TFcut.so/TFLcut.C > CMakeFiles/TFcut.dir/TFLcut.C.i

CMakeFiles/TFcut.dir/TFLcut.C.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TFcut.dir/TFLcut.C.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/boeglin.1/HallA/analysis/TFcut.so/TFLcut.C -o CMakeFiles/TFcut.dir/TFLcut.C.s

CMakeFiles/TFcut.dir/TFLcut.C.o.requires:

.PHONY : CMakeFiles/TFcut.dir/TFLcut.C.o.requires

CMakeFiles/TFcut.dir/TFLcut.C.o.provides: CMakeFiles/TFcut.dir/TFLcut.C.o.requires
	$(MAKE) -f CMakeFiles/TFcut.dir/build.make CMakeFiles/TFcut.dir/TFLcut.C.o.provides.build
.PHONY : CMakeFiles/TFcut.dir/TFLcut.C.o.provides

CMakeFiles/TFcut.dir/TFLcut.C.o.provides.build: CMakeFiles/TFcut.dir/TFLcut.C.o


CMakeFiles/TFcut.dir/TFcutDict.cxx.o: CMakeFiles/TFcut.dir/flags.make
CMakeFiles/TFcut.dir/TFcutDict.cxx.o: TFcutDict.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/boeglin.1/HallA/analysis/TFcut.so/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TFcut.dir/TFcutDict.cxx.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TFcut.dir/TFcutDict.cxx.o -c /data/boeglin.1/HallA/analysis/TFcut.so/build/TFcutDict.cxx

CMakeFiles/TFcut.dir/TFcutDict.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TFcut.dir/TFcutDict.cxx.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/boeglin.1/HallA/analysis/TFcut.so/build/TFcutDict.cxx > CMakeFiles/TFcut.dir/TFcutDict.cxx.i

CMakeFiles/TFcut.dir/TFcutDict.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TFcut.dir/TFcutDict.cxx.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/boeglin.1/HallA/analysis/TFcut.so/build/TFcutDict.cxx -o CMakeFiles/TFcut.dir/TFcutDict.cxx.s

CMakeFiles/TFcut.dir/TFcutDict.cxx.o.requires:

.PHONY : CMakeFiles/TFcut.dir/TFcutDict.cxx.o.requires

CMakeFiles/TFcut.dir/TFcutDict.cxx.o.provides: CMakeFiles/TFcut.dir/TFcutDict.cxx.o.requires
	$(MAKE) -f CMakeFiles/TFcut.dir/build.make CMakeFiles/TFcut.dir/TFcutDict.cxx.o.provides.build
.PHONY : CMakeFiles/TFcut.dir/TFcutDict.cxx.o.provides

CMakeFiles/TFcut.dir/TFcutDict.cxx.o.provides.build: CMakeFiles/TFcut.dir/TFcutDict.cxx.o


# Object files for target TFcut
TFcut_OBJECTS = \
"CMakeFiles/TFcut.dir/TFWcut.C.o" \
"CMakeFiles/TFcut.dir/TFLcut.C.o" \
"CMakeFiles/TFcut.dir/TFcutDict.cxx.o"

# External object files for target TFcut
TFcut_EXTERNAL_OBJECTS =

libTFcut.dylib: CMakeFiles/TFcut.dir/TFWcut.C.o
libTFcut.dylib: CMakeFiles/TFcut.dir/TFLcut.C.o
libTFcut.dylib: CMakeFiles/TFcut.dir/TFcutDict.cxx.o
libTFcut.dylib: CMakeFiles/TFcut.dir/build.make
libTFcut.dylib: CMakeFiles/TFcut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/boeglin.1/HallA/analysis/TFcut.so/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library libTFcut.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TFcut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TFcut.dir/build: libTFcut.dylib

.PHONY : CMakeFiles/TFcut.dir/build

CMakeFiles/TFcut.dir/requires: CMakeFiles/TFcut.dir/TFWcut.C.o.requires
CMakeFiles/TFcut.dir/requires: CMakeFiles/TFcut.dir/TFLcut.C.o.requires
CMakeFiles/TFcut.dir/requires: CMakeFiles/TFcut.dir/TFcutDict.cxx.o.requires

.PHONY : CMakeFiles/TFcut.dir/requires

CMakeFiles/TFcut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TFcut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TFcut.dir/clean

CMakeFiles/TFcut.dir/depend: TFcutDict.cxx
CMakeFiles/TFcut.dir/depend: libTFcut_rdict.pcm
CMakeFiles/TFcut.dir/depend: libTFcut.rootmap
	cd /data/boeglin.1/HallA/analysis/TFcut.so/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/boeglin.1/HallA/analysis/TFcut.so /data/boeglin.1/HallA/analysis/TFcut.so /data/boeglin.1/HallA/analysis/TFcut.so/build /data/boeglin.1/HallA/analysis/TFcut.so/build /data/boeglin.1/HallA/analysis/TFcut.so/build/CMakeFiles/TFcut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TFcut.dir/depend

