# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/alexander/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alexander/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7142.21/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexander/github/Alisher_lessons/Alisher_level_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/tests.dir/flags.make

test/CMakeFiles/tests.dir/main.cpp.o: test/CMakeFiles/tests.dir/flags.make
test/CMakeFiles/tests.dir/main.cpp.o: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/tests.dir/main.cpp.o"
	cd /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/main.cpp.o -c /home/alexander/github/Alisher_lessons/Alisher_level_1/test/main.cpp

test/CMakeFiles/tests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/main.cpp.i"
	cd /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/github/Alisher_lessons/Alisher_level_1/test/main.cpp > CMakeFiles/tests.dir/main.cpp.i

test/CMakeFiles/tests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/main.cpp.s"
	cd /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/github/Alisher_lessons/Alisher_level_1/test/main.cpp -o CMakeFiles/tests.dir/main.cpp.s

test/CMakeFiles/tests.dir/variable.cpp.o: test/CMakeFiles/tests.dir/flags.make
test/CMakeFiles/tests.dir/variable.cpp.o: ../test/variable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/tests.dir/variable.cpp.o"
	cd /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/variable.cpp.o -c /home/alexander/github/Alisher_lessons/Alisher_level_1/test/variable.cpp

test/CMakeFiles/tests.dir/variable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/variable.cpp.i"
	cd /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexander/github/Alisher_lessons/Alisher_level_1/test/variable.cpp > CMakeFiles/tests.dir/variable.cpp.i

test/CMakeFiles/tests.dir/variable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/variable.cpp.s"
	cd /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexander/github/Alisher_lessons/Alisher_level_1/test/variable.cpp -o CMakeFiles/tests.dir/variable.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/main.cpp.o" \
"CMakeFiles/tests.dir/variable.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

test/tests: test/CMakeFiles/tests.dir/main.cpp.o
test/tests: test/CMakeFiles/tests.dir/variable.cpp.o
test/tests: test/CMakeFiles/tests.dir/build.make
test/tests: src/libVariable_lib.a
test/tests: test/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tests"
	cd /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/tests.dir/build: test/tests

.PHONY : test/CMakeFiles/tests.dir/build

test/CMakeFiles/tests.dir/clean:
	cd /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/tests.dir/clean

test/CMakeFiles/tests.dir/depend:
	cd /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexander/github/Alisher_lessons/Alisher_level_1 /home/alexander/github/Alisher_lessons/Alisher_level_1/test /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test /home/alexander/github/Alisher_lessons/Alisher_level_1/cmake-build-debug/test/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/tests.dir/depend
