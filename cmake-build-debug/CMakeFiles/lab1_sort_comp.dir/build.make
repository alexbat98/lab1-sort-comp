# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /cygdrive/c/Users/alexb/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/alexb/.CLion2016.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/alexb/ClionProjects/lab1-sort-comp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab1_sort_comp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab1_sort_comp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab1_sort_comp.dir/flags.make

CMakeFiles/lab1_sort_comp.dir/main.c.o: CMakeFiles/lab1_sort_comp.dir/flags.make
CMakeFiles/lab1_sort_comp.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/alexb/ClionProjects/lab1-sort-comp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab1_sort_comp.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab1_sort_comp.dir/main.c.o   -c /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/main.c

CMakeFiles/lab1_sort_comp.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab1_sort_comp.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/main.c > CMakeFiles/lab1_sort_comp.dir/main.c.i

CMakeFiles/lab1_sort_comp.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab1_sort_comp.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/main.c -o CMakeFiles/lab1_sort_comp.dir/main.c.s

CMakeFiles/lab1_sort_comp.dir/main.c.o.requires:

.PHONY : CMakeFiles/lab1_sort_comp.dir/main.c.o.requires

CMakeFiles/lab1_sort_comp.dir/main.c.o.provides: CMakeFiles/lab1_sort_comp.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/lab1_sort_comp.dir/build.make CMakeFiles/lab1_sort_comp.dir/main.c.o.provides.build
.PHONY : CMakeFiles/lab1_sort_comp.dir/main.c.o.provides

CMakeFiles/lab1_sort_comp.dir/main.c.o.provides.build: CMakeFiles/lab1_sort_comp.dir/main.c.o


CMakeFiles/lab1_sort_comp.dir/algorithms.c.o: CMakeFiles/lab1_sort_comp.dir/flags.make
CMakeFiles/lab1_sort_comp.dir/algorithms.c.o: ../algorithms.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/alexb/ClionProjects/lab1-sort-comp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab1_sort_comp.dir/algorithms.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab1_sort_comp.dir/algorithms.c.o   -c /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/algorithms.c

CMakeFiles/lab1_sort_comp.dir/algorithms.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab1_sort_comp.dir/algorithms.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/algorithms.c > CMakeFiles/lab1_sort_comp.dir/algorithms.c.i

CMakeFiles/lab1_sort_comp.dir/algorithms.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab1_sort_comp.dir/algorithms.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/algorithms.c -o CMakeFiles/lab1_sort_comp.dir/algorithms.c.s

CMakeFiles/lab1_sort_comp.dir/algorithms.c.o.requires:

.PHONY : CMakeFiles/lab1_sort_comp.dir/algorithms.c.o.requires

CMakeFiles/lab1_sort_comp.dir/algorithms.c.o.provides: CMakeFiles/lab1_sort_comp.dir/algorithms.c.o.requires
	$(MAKE) -f CMakeFiles/lab1_sort_comp.dir/build.make CMakeFiles/lab1_sort_comp.dir/algorithms.c.o.provides.build
.PHONY : CMakeFiles/lab1_sort_comp.dir/algorithms.c.o.provides

CMakeFiles/lab1_sort_comp.dir/algorithms.c.o.provides.build: CMakeFiles/lab1_sort_comp.dir/algorithms.c.o


CMakeFiles/lab1_sort_comp.dir/utils.c.o: CMakeFiles/lab1_sort_comp.dir/flags.make
CMakeFiles/lab1_sort_comp.dir/utils.c.o: ../utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/alexb/ClionProjects/lab1-sort-comp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab1_sort_comp.dir/utils.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab1_sort_comp.dir/utils.c.o   -c /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/utils.c

CMakeFiles/lab1_sort_comp.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab1_sort_comp.dir/utils.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/utils.c > CMakeFiles/lab1_sort_comp.dir/utils.c.i

CMakeFiles/lab1_sort_comp.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab1_sort_comp.dir/utils.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/utils.c -o CMakeFiles/lab1_sort_comp.dir/utils.c.s

CMakeFiles/lab1_sort_comp.dir/utils.c.o.requires:

.PHONY : CMakeFiles/lab1_sort_comp.dir/utils.c.o.requires

CMakeFiles/lab1_sort_comp.dir/utils.c.o.provides: CMakeFiles/lab1_sort_comp.dir/utils.c.o.requires
	$(MAKE) -f CMakeFiles/lab1_sort_comp.dir/build.make CMakeFiles/lab1_sort_comp.dir/utils.c.o.provides.build
.PHONY : CMakeFiles/lab1_sort_comp.dir/utils.c.o.provides

CMakeFiles/lab1_sort_comp.dir/utils.c.o.provides.build: CMakeFiles/lab1_sort_comp.dir/utils.c.o


# Object files for target lab1_sort_comp
lab1_sort_comp_OBJECTS = \
"CMakeFiles/lab1_sort_comp.dir/main.c.o" \
"CMakeFiles/lab1_sort_comp.dir/algorithms.c.o" \
"CMakeFiles/lab1_sort_comp.dir/utils.c.o"

# External object files for target lab1_sort_comp
lab1_sort_comp_EXTERNAL_OBJECTS =

lab1_sort_comp.exe: CMakeFiles/lab1_sort_comp.dir/main.c.o
lab1_sort_comp.exe: CMakeFiles/lab1_sort_comp.dir/algorithms.c.o
lab1_sort_comp.exe: CMakeFiles/lab1_sort_comp.dir/utils.c.o
lab1_sort_comp.exe: CMakeFiles/lab1_sort_comp.dir/build.make
lab1_sort_comp.exe: CMakeFiles/lab1_sort_comp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/alexb/ClionProjects/lab1-sort-comp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable lab1_sort_comp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab1_sort_comp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab1_sort_comp.dir/build: lab1_sort_comp.exe

.PHONY : CMakeFiles/lab1_sort_comp.dir/build

CMakeFiles/lab1_sort_comp.dir/requires: CMakeFiles/lab1_sort_comp.dir/main.c.o.requires
CMakeFiles/lab1_sort_comp.dir/requires: CMakeFiles/lab1_sort_comp.dir/algorithms.c.o.requires
CMakeFiles/lab1_sort_comp.dir/requires: CMakeFiles/lab1_sort_comp.dir/utils.c.o.requires

.PHONY : CMakeFiles/lab1_sort_comp.dir/requires

CMakeFiles/lab1_sort_comp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab1_sort_comp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab1_sort_comp.dir/clean

CMakeFiles/lab1_sort_comp.dir/depend:
	cd /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/alexb/ClionProjects/lab1-sort-comp /cygdrive/d/alexb/ClionProjects/lab1-sort-comp /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/cmake-build-debug /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/cmake-build-debug /cygdrive/d/alexb/ClionProjects/lab1-sort-comp/cmake-build-debug/CMakeFiles/lab1_sort_comp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab1_sort_comp.dir/depend

