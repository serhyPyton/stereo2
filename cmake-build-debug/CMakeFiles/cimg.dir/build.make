# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/makarenko/hacked/CLion-2019.3.5/clion-2019.3.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/makarenko/hacked/CLion-2019.3.5/clion-2019.3.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/makarenko/CLionProjects/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/makarenko/CLionProjects/lab2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cimg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cimg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cimg.dir/flags.make

# Object files for target cimg
cimg_OBJECTS =

# External object files for target cimg
cimg_EXTERNAL_OBJECTS =

libcimg.so: CMakeFiles/cimg.dir/build.make
libcimg.so: CMakeFiles/cimg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/makarenko/CLionProjects/lab2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX shared library libcimg.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cimg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cimg.dir/build: libcimg.so

.PHONY : CMakeFiles/cimg.dir/build

CMakeFiles/cimg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cimg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cimg.dir/clean

CMakeFiles/cimg.dir/depend:
	cd /home/makarenko/CLionProjects/lab2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/makarenko/CLionProjects/lab2 /home/makarenko/CLionProjects/lab2 /home/makarenko/CLionProjects/lab2/cmake-build-debug /home/makarenko/CLionProjects/lab2/cmake-build-debug /home/makarenko/CLionProjects/lab2/cmake-build-debug/CMakeFiles/cimg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cimg.dir/depend
