# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cutehater/CLionProjects/HuffmanArchiver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ARCHIVER.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ARCHIVER.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ARCHIVER.dir/flags.make

CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.o: CMakeFiles/ARCHIVER.dir/flags.make
CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.o: ../Archiver/Archiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.o -c /home/cutehater/CLionProjects/HuffmanArchiver/Archiver/Archiver.cpp

CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cutehater/CLionProjects/HuffmanArchiver/Archiver/Archiver.cpp > CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.i

CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cutehater/CLionProjects/HuffmanArchiver/Archiver/Archiver.cpp -o CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.s

# Object files for target ARCHIVER
ARCHIVER_OBJECTS = \
"CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.o"

# External object files for target ARCHIVER
ARCHIVER_EXTERNAL_OBJECTS =

libARCHIVER.a: CMakeFiles/ARCHIVER.dir/Archiver/Archiver.cpp.o
libARCHIVER.a: CMakeFiles/ARCHIVER.dir/build.make
libARCHIVER.a: CMakeFiles/ARCHIVER.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libARCHIVER.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ARCHIVER.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ARCHIVER.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ARCHIVER.dir/build: libARCHIVER.a
.PHONY : CMakeFiles/ARCHIVER.dir/build

CMakeFiles/ARCHIVER.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ARCHIVER.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ARCHIVER.dir/clean

CMakeFiles/ARCHIVER.dir/depend:
	cd /home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cutehater/CLionProjects/HuffmanArchiver /home/cutehater/CLionProjects/HuffmanArchiver /home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug /home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug /home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug/CMakeFiles/ARCHIVER.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ARCHIVER.dir/depend

