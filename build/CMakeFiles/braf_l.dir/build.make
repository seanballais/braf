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
include CMakeFiles/braf_l.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/braf_l.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/braf_l.dir/flags.make

CMakeFiles/braf_l.dir/src/braf.c.o: CMakeFiles/braf_l.dir/flags.make
CMakeFiles/braf_l.dir/src/braf.c.o: ../src/braf.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/braf_l.dir/src/braf.c.o"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/braf_l.dir/src/braf.c.o   -c "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/braf.c"

CMakeFiles/braf_l.dir/src/braf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/braf_l.dir/src/braf.c.i"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -E "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/braf.c" > CMakeFiles/braf_l.dir/src/braf.c.i

CMakeFiles/braf_l.dir/src/braf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/braf_l.dir/src/braf.c.s"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -S "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/braf.c" -o CMakeFiles/braf_l.dir/src/braf.c.s

CMakeFiles/braf_l.dir/src/braf.c.o.requires:
.PHONY : CMakeFiles/braf_l.dir/src/braf.c.o.requires

CMakeFiles/braf_l.dir/src/braf.c.o.provides: CMakeFiles/braf_l.dir/src/braf.c.o.requires
	$(MAKE) -f CMakeFiles/braf_l.dir/build.make CMakeFiles/braf_l.dir/src/braf.c.o.provides.build
.PHONY : CMakeFiles/braf_l.dir/src/braf.c.o.provides

CMakeFiles/braf_l.dir/src/braf.c.o.provides.build: CMakeFiles/braf_l.dir/src/braf.c.o

CMakeFiles/braf_l.dir/src/error_check.c.o: CMakeFiles/braf_l.dir/flags.make
CMakeFiles/braf_l.dir/src/error_check.c.o: ../src/error_check.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build/CMakeFiles" $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/braf_l.dir/src/error_check.c.o"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/braf_l.dir/src/error_check.c.o   -c "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/error_check.c"

CMakeFiles/braf_l.dir/src/error_check.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/braf_l.dir/src/error_check.c.i"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -E "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/error_check.c" > CMakeFiles/braf_l.dir/src/error_check.c.i

CMakeFiles/braf_l.dir/src/error_check.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/braf_l.dir/src/error_check.c.s"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -S "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/error_check.c" -o CMakeFiles/braf_l.dir/src/error_check.c.s

CMakeFiles/braf_l.dir/src/error_check.c.o.requires:
.PHONY : CMakeFiles/braf_l.dir/src/error_check.c.o.requires

CMakeFiles/braf_l.dir/src/error_check.c.o.provides: CMakeFiles/braf_l.dir/src/error_check.c.o.requires
	$(MAKE) -f CMakeFiles/braf_l.dir/build.make CMakeFiles/braf_l.dir/src/error_check.c.o.provides.build
.PHONY : CMakeFiles/braf_l.dir/src/error_check.c.o.provides

CMakeFiles/braf_l.dir/src/error_check.c.o.provides.build: CMakeFiles/braf_l.dir/src/error_check.c.o

CMakeFiles/braf_l.dir/src/util.c.o: CMakeFiles/braf_l.dir/flags.make
CMakeFiles/braf_l.dir/src/util.c.o: ../src/util.c
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build/CMakeFiles" $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/braf_l.dir/src/util.c.o"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/braf_l.dir/src/util.c.o   -c "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/util.c"

CMakeFiles/braf_l.dir/src/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/braf_l.dir/src/util.c.i"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -E "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/util.c" > CMakeFiles/braf_l.dir/src/util.c.i

CMakeFiles/braf_l.dir/src/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/braf_l.dir/src/util.c.s"
	/usr/bin/clang  $(C_DEFINES) $(C_FLAGS) -S "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/src/util.c" -o CMakeFiles/braf_l.dir/src/util.c.s

CMakeFiles/braf_l.dir/src/util.c.o.requires:
.PHONY : CMakeFiles/braf_l.dir/src/util.c.o.requires

CMakeFiles/braf_l.dir/src/util.c.o.provides: CMakeFiles/braf_l.dir/src/util.c.o.requires
	$(MAKE) -f CMakeFiles/braf_l.dir/build.make CMakeFiles/braf_l.dir/src/util.c.o.provides.build
.PHONY : CMakeFiles/braf_l.dir/src/util.c.o.provides

CMakeFiles/braf_l.dir/src/util.c.o.provides.build: CMakeFiles/braf_l.dir/src/util.c.o

# Object files for target braf_l
braf_l_OBJECTS = \
"CMakeFiles/braf_l.dir/src/braf.c.o" \
"CMakeFiles/braf_l.dir/src/error_check.c.o" \
"CMakeFiles/braf_l.dir/src/util.c.o"

# External object files for target braf_l
braf_l_EXTERNAL_OBJECTS =

libbraf_l.a: CMakeFiles/braf_l.dir/src/braf.c.o
libbraf_l.a: CMakeFiles/braf_l.dir/src/error_check.c.o
libbraf_l.a: CMakeFiles/braf_l.dir/src/util.c.o
libbraf_l.a: CMakeFiles/braf_l.dir/build.make
libbraf_l.a: CMakeFiles/braf_l.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libbraf_l.a"
	$(CMAKE_COMMAND) -P CMakeFiles/braf_l.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/braf_l.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/braf_l.dir/build: libbraf_l.a
.PHONY : CMakeFiles/braf_l.dir/build

CMakeFiles/braf_l.dir/requires: CMakeFiles/braf_l.dir/src/braf.c.o.requires
CMakeFiles/braf_l.dir/requires: CMakeFiles/braf_l.dir/src/error_check.c.o.requires
CMakeFiles/braf_l.dir/requires: CMakeFiles/braf_l.dir/src/util.c.o.requires
.PHONY : CMakeFiles/braf_l.dir/requires

CMakeFiles/braf_l.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/braf_l.dir/cmake_clean.cmake
.PHONY : CMakeFiles/braf_l.dir/clean

CMakeFiles/braf_l.dir/depend:
	cd "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build" "/home/seanballais/School/UPVTC/CMSC11/Final Project/braf/build/CMakeFiles/braf_l.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/braf_l.dir/depend

