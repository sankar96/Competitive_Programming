# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sankar-5526/CLionProjects/Competitive_Programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sankar-5526/CLionProjects/Competitive_Programming/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Competitive_Programming.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Competitive_Programming.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Competitive_Programming.dir/flags.make

CMakeFiles/Competitive_Programming.dir/main.cpp.o: CMakeFiles/Competitive_Programming.dir/flags.make
CMakeFiles/Competitive_Programming.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sankar-5526/CLionProjects/Competitive_Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Competitive_Programming.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Competitive_Programming.dir/main.cpp.o -c /Users/sankar-5526/CLionProjects/Competitive_Programming/main.cpp

CMakeFiles/Competitive_Programming.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Competitive_Programming.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sankar-5526/CLionProjects/Competitive_Programming/main.cpp > CMakeFiles/Competitive_Programming.dir/main.cpp.i

CMakeFiles/Competitive_Programming.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Competitive_Programming.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sankar-5526/CLionProjects/Competitive_Programming/main.cpp -o CMakeFiles/Competitive_Programming.dir/main.cpp.s

CMakeFiles/Competitive_Programming.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Competitive_Programming.dir/main.cpp.o.requires

CMakeFiles/Competitive_Programming.dir/main.cpp.o.provides: CMakeFiles/Competitive_Programming.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Competitive_Programming.dir/build.make CMakeFiles/Competitive_Programming.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Competitive_Programming.dir/main.cpp.o.provides

CMakeFiles/Competitive_Programming.dir/main.cpp.o.provides.build: CMakeFiles/Competitive_Programming.dir/main.cpp.o


# Object files for target Competitive_Programming
Competitive_Programming_OBJECTS = \
"CMakeFiles/Competitive_Programming.dir/main.cpp.o"

# External object files for target Competitive_Programming
Competitive_Programming_EXTERNAL_OBJECTS =

Competitive_Programming: CMakeFiles/Competitive_Programming.dir/main.cpp.o
Competitive_Programming: CMakeFiles/Competitive_Programming.dir/build.make
Competitive_Programming: CMakeFiles/Competitive_Programming.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sankar-5526/CLionProjects/Competitive_Programming/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Competitive_Programming"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Competitive_Programming.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Competitive_Programming.dir/build: Competitive_Programming

.PHONY : CMakeFiles/Competitive_Programming.dir/build

CMakeFiles/Competitive_Programming.dir/requires: CMakeFiles/Competitive_Programming.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Competitive_Programming.dir/requires

CMakeFiles/Competitive_Programming.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Competitive_Programming.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Competitive_Programming.dir/clean

CMakeFiles/Competitive_Programming.dir/depend:
	cd /Users/sankar-5526/CLionProjects/Competitive_Programming/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sankar-5526/CLionProjects/Competitive_Programming /Users/sankar-5526/CLionProjects/Competitive_Programming /Users/sankar-5526/CLionProjects/Competitive_Programming/cmake-build-debug /Users/sankar-5526/CLionProjects/Competitive_Programming/cmake-build-debug /Users/sankar-5526/CLionProjects/Competitive_Programming/cmake-build-debug/CMakeFiles/Competitive_Programming.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Competitive_Programming.dir/depend

