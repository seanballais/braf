# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build"

# Include any dependencies generated for this target.
include CMakeFiles/braf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/braf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/braf.dir/flags.make

CMakeFiles/braf.dir/src/main.c.o: CMakeFiles/braf.dir/flags.make
CMakeFiles/braf.dir/src/main.c.o: ../src/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/braf.dir/src/main.c.o"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/braf.dir/src/main.c.o   -c "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/main.c"

CMakeFiles/braf.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/braf.dir/src/main.c.i"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -E "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/main.c" > CMakeFiles/braf.dir/src/main.c.i

CMakeFiles/braf.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/braf.dir/src/main.c.s"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -S "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/main.c" -o CMakeFiles/braf.dir/src/main.c.s

CMakeFiles/braf.dir/src/main.c.o.requires:
.PHONY : CMakeFiles/braf.dir/src/main.c.o.requires

CMakeFiles/braf.dir/src/main.c.o.provides: CMakeFiles/braf.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/braf.dir/build.make CMakeFiles/braf.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/braf.dir/src/main.c.o.provides

CMakeFiles/braf.dir/src/main.c.o.provides.build: CMakeFiles/braf.dir/src/main.c.o

CMakeFiles/braf.dir/src/interactive_mode.c.o: CMakeFiles/braf.dir/flags.make
CMakeFiles/braf.dir/src/interactive_mode.c.o: ../src/interactive_mode.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build/CMakeFiles" $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/braf.dir/src/interactive_mode.c.o"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/braf.dir/src/interactive_mode.c.o   -c "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/interactive_mode.c"

CMakeFiles/braf.dir/src/interactive_mode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/braf.dir/src/interactive_mode.c.i"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -E "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/interactive_mode.c" > CMakeFiles/braf.dir/src/interactive_mode.c.i

CMakeFiles/braf.dir/src/interactive_mode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/braf.dir/src/interactive_mode.c.s"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -S "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/interactive_mode.c" -o CMakeFiles/braf.dir/src/interactive_mode.c.s

CMakeFiles/braf.dir/src/interactive_mode.c.o.requires:
.PHONY : CMakeFiles/braf.dir/src/interactive_mode.c.o.requires

CMakeFiles/braf.dir/src/interactive_mode.c.o.provides: CMakeFiles/braf.dir/src/interactive_mode.c.o.requires
	$(MAKE) -f CMakeFiles/braf.dir/build.make CMakeFiles/braf.dir/src/interactive_mode.c.o.provides.build
.PHONY : CMakeFiles/braf.dir/src/interactive_mode.c.o.provides

CMakeFiles/braf.dir/src/interactive_mode.c.o.provides.build: CMakeFiles/braf.dir/src/interactive_mode.c.o

# Object files for target braf
braf_OBJECTS = \
"CMakeFiles/braf.dir/src/main.c.o" \
"CMakeFiles/braf.dir/src/interactive_mode.c.o"

# External object files for target braf
braf_EXTERNAL_OBJECTS =

braf: CMakeFiles/braf.dir/src/main.c.o
braf: CMakeFiles/braf.dir/src/interactive_mode.c.o
braf: CMakeFiles/braf.dir/build.make
braf: CMakeFiles/braf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable braf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/braf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/braf.dir/build: braf
.PHONY : CMakeFiles/braf.dir/build

CMakeFiles/braf.dir/requires: CMakeFiles/braf.dir/src/main.c.o.requires
CMakeFiles/braf.dir/requires: CMakeFiles/braf.dir/src/interactive_mode.c.o.requires
.PHONY : CMakeFiles/braf.dir/requires

CMakeFiles/braf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/braf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/braf.dir/clean

CMakeFiles/braf.dir/depend:
	cd "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build/CMakeFiles/braf.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/braf.dir/depend
