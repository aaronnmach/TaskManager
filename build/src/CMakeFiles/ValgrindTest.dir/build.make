# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aaronnmsch/Downloads/TaskPro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aaronnmsch/Downloads/TaskPro/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ValgrindTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/ValgrindTest.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ValgrindTest.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ValgrindTest.dir/flags.make

src/CMakeFiles/ValgrindTest.dir/main2.cpp.o: src/CMakeFiles/ValgrindTest.dir/flags.make
src/CMakeFiles/ValgrindTest.dir/main2.cpp.o: /Users/aaronnmsch/Downloads/TaskPro/src/main2.cpp
src/CMakeFiles/ValgrindTest.dir/main2.cpp.o: src/CMakeFiles/ValgrindTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aaronnmsch/Downloads/TaskPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ValgrindTest.dir/main2.cpp.o"
	cd /Users/aaronnmsch/Downloads/TaskPro/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ValgrindTest.dir/main2.cpp.o -MF CMakeFiles/ValgrindTest.dir/main2.cpp.o.d -o CMakeFiles/ValgrindTest.dir/main2.cpp.o -c /Users/aaronnmsch/Downloads/TaskPro/src/main2.cpp

src/CMakeFiles/ValgrindTest.dir/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ValgrindTest.dir/main2.cpp.i"
	cd /Users/aaronnmsch/Downloads/TaskPro/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aaronnmsch/Downloads/TaskPro/src/main2.cpp > CMakeFiles/ValgrindTest.dir/main2.cpp.i

src/CMakeFiles/ValgrindTest.dir/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ValgrindTest.dir/main2.cpp.s"
	cd /Users/aaronnmsch/Downloads/TaskPro/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aaronnmsch/Downloads/TaskPro/src/main2.cpp -o CMakeFiles/ValgrindTest.dir/main2.cpp.s

# Object files for target ValgrindTest
ValgrindTest_OBJECTS = \
"CMakeFiles/ValgrindTest.dir/main2.cpp.o"

# External object files for target ValgrindTest
ValgrindTest_EXTERNAL_OBJECTS =

bin/ValgrindTest: src/CMakeFiles/ValgrindTest.dir/main2.cpp.o
bin/ValgrindTest: src/CMakeFiles/ValgrindTest.dir/build.make
bin/ValgrindTest: lib/libtaskLibrary.a
bin/ValgrindTest: src/CMakeFiles/ValgrindTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aaronnmsch/Downloads/TaskPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/ValgrindTest"
	cd /Users/aaronnmsch/Downloads/TaskPro/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ValgrindTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ValgrindTest.dir/build: bin/ValgrindTest
.PHONY : src/CMakeFiles/ValgrindTest.dir/build

src/CMakeFiles/ValgrindTest.dir/clean:
	cd /Users/aaronnmsch/Downloads/TaskPro/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ValgrindTest.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ValgrindTest.dir/clean

src/CMakeFiles/ValgrindTest.dir/depend:
	cd /Users/aaronnmsch/Downloads/TaskPro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aaronnmsch/Downloads/TaskPro /Users/aaronnmsch/Downloads/TaskPro/src /Users/aaronnmsch/Downloads/TaskPro/build /Users/aaronnmsch/Downloads/TaskPro/build/src /Users/aaronnmsch/Downloads/TaskPro/build/src/CMakeFiles/ValgrindTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ValgrindTest.dir/depend

