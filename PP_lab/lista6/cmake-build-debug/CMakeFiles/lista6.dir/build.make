# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/madatt/Studbaza/PP_lab/lista6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/madatt/Studbaza/PP_lab/lista6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lista6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lista6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lista6.dir/flags.make

CMakeFiles/lista6.dir/main.cpp.o: CMakeFiles/lista6.dir/flags.make
CMakeFiles/lista6.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/madatt/Studbaza/PP_lab/lista6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lista6.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lista6.dir/main.cpp.o -c /home/madatt/Studbaza/PP_lab/lista6/main.cpp

CMakeFiles/lista6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lista6.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/madatt/Studbaza/PP_lab/lista6/main.cpp > CMakeFiles/lista6.dir/main.cpp.i

CMakeFiles/lista6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lista6.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/madatt/Studbaza/PP_lab/lista6/main.cpp -o CMakeFiles/lista6.dir/main.cpp.s

# Object files for target lista6
lista6_OBJECTS = \
"CMakeFiles/lista6.dir/main.cpp.o"

# External object files for target lista6
lista6_EXTERNAL_OBJECTS =

lista6: CMakeFiles/lista6.dir/main.cpp.o
lista6: CMakeFiles/lista6.dir/build.make
lista6: CMakeFiles/lista6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/madatt/Studbaza/PP_lab/lista6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lista6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lista6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lista6.dir/build: lista6

.PHONY : CMakeFiles/lista6.dir/build

CMakeFiles/lista6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lista6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lista6.dir/clean

CMakeFiles/lista6.dir/depend:
	cd /home/madatt/Studbaza/PP_lab/lista6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/madatt/Studbaza/PP_lab/lista6 /home/madatt/Studbaza/PP_lab/lista6 /home/madatt/Studbaza/PP_lab/lista6/cmake-build-debug /home/madatt/Studbaza/PP_lab/lista6/cmake-build-debug /home/madatt/Studbaza/PP_lab/lista6/cmake-build-debug/CMakeFiles/lista6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lista6.dir/depend

