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
include CMakeFiles/archiver.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/archiver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/archiver.dir/flags.make

CMakeFiles/archiver.dir/main.cpp.o: CMakeFiles/archiver.dir/flags.make
CMakeFiles/archiver.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/archiver.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/archiver.dir/main.cpp.o -c /home/cutehater/CLionProjects/HuffmanArchiver/main.cpp

CMakeFiles/archiver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/archiver.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cutehater/CLionProjects/HuffmanArchiver/main.cpp > CMakeFiles/archiver.dir/main.cpp.i

CMakeFiles/archiver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/archiver.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cutehater/CLionProjects/HuffmanArchiver/main.cpp -o CMakeFiles/archiver.dir/main.cpp.s

CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.o: CMakeFiles/archiver.dir/flags.make
CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.o: ../PriorityQueue/PriorityQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.o -c /home/cutehater/CLionProjects/HuffmanArchiver/PriorityQueue/PriorityQueue.cpp

CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cutehater/CLionProjects/HuffmanArchiver/PriorityQueue/PriorityQueue.cpp > CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.i

CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cutehater/CLionProjects/HuffmanArchiver/PriorityQueue/PriorityQueue.cpp -o CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.s

# Object files for target archiver
archiver_OBJECTS = \
"CMakeFiles/archiver.dir/main.cpp.o" \
"CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.o"

# External object files for target archiver
archiver_EXTERNAL_OBJECTS =

archiver: CMakeFiles/archiver.dir/main.cpp.o
archiver: CMakeFiles/archiver.dir/PriorityQueue/PriorityQueue.cpp.o
archiver: CMakeFiles/archiver.dir/build.make
archiver: libARCHIVER.a
archiver: libARGUMENT_PARSER.a
archiver: libEXTRACTOR.a
archiver: libMESSENGER.a
archiver: libPRIORITY_QUEUE.a
archiver: libREADER.a
archiver: libTRIE.a
archiver: libWRITER.a
archiver: CMakeFiles/archiver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable archiver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/archiver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/archiver.dir/build: archiver
.PHONY : CMakeFiles/archiver.dir/build

CMakeFiles/archiver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/archiver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/archiver.dir/clean

CMakeFiles/archiver.dir/depend:
	cd /home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cutehater/CLionProjects/HuffmanArchiver /home/cutehater/CLionProjects/HuffmanArchiver /home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug /home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug /home/cutehater/CLionProjects/HuffmanArchiver/cmake-build-debug/CMakeFiles/archiver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/archiver.dir/depend

