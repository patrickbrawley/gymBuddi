# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gymbuddi3/Examples/qwt-example/qwt-example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gymbuddi3/Examples/qwt-example/qwt-example

# Utility rule file for qwt-example_autogen.

# Include the progress variables for this target.
include CMakeFiles/qwt-example_autogen.dir/progress.make

CMakeFiles/qwt-example_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/gymbuddi3/Examples/qwt-example/qwt-example/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target qwt-example"
	/usr/bin/cmake -E cmake_autogen /home/gymbuddi3/Examples/qwt-example/qwt-example/CMakeFiles/qwt-example_autogen.dir/AutogenInfo.json ""

qwt-example_autogen: CMakeFiles/qwt-example_autogen
qwt-example_autogen: CMakeFiles/qwt-example_autogen.dir/build.make

.PHONY : qwt-example_autogen

# Rule to build all files generated by this target.
CMakeFiles/qwt-example_autogen.dir/build: qwt-example_autogen

.PHONY : CMakeFiles/qwt-example_autogen.dir/build

CMakeFiles/qwt-example_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qwt-example_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qwt-example_autogen.dir/clean

CMakeFiles/qwt-example_autogen.dir/depend:
	cd /home/gymbuddi3/Examples/qwt-example/qwt-example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gymbuddi3/Examples/qwt-example/qwt-example /home/gymbuddi3/Examples/qwt-example/qwt-example /home/gymbuddi3/Examples/qwt-example/qwt-example /home/gymbuddi3/Examples/qwt-example/qwt-example /home/gymbuddi3/Examples/qwt-example/qwt-example/CMakeFiles/qwt-example_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qwt-example_autogen.dir/depend

