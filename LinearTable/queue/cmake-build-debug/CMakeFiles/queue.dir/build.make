# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2017.2.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2017.2.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\workspace\C\dataStructure\LinearTable\queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\workspace\C\dataStructure\LinearTable\queue\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/queue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/queue.dir/flags.make

CMakeFiles/queue.dir/main.cpp.obj: CMakeFiles/queue.dir/flags.make
CMakeFiles/queue.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\workspace\C\dataStructure\LinearTable\queue\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/queue.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\queue.dir\main.cpp.obj -c E:\workspace\C\dataStructure\LinearTable\queue\main.cpp

CMakeFiles/queue.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queue.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\workspace\C\dataStructure\LinearTable\queue\main.cpp > CMakeFiles\queue.dir\main.cpp.i

CMakeFiles/queue.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queue.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\workspace\C\dataStructure\LinearTable\queue\main.cpp -o CMakeFiles\queue.dir\main.cpp.s

CMakeFiles/queue.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/queue.dir/main.cpp.obj.requires

CMakeFiles/queue.dir/main.cpp.obj.provides: CMakeFiles/queue.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\queue.dir\build.make CMakeFiles/queue.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/queue.dir/main.cpp.obj.provides

CMakeFiles/queue.dir/main.cpp.obj.provides.build: CMakeFiles/queue.dir/main.cpp.obj


# Object files for target queue
queue_OBJECTS = \
"CMakeFiles/queue.dir/main.cpp.obj"

# External object files for target queue
queue_EXTERNAL_OBJECTS =

queue.exe: CMakeFiles/queue.dir/main.cpp.obj
queue.exe: CMakeFiles/queue.dir/build.make
queue.exe: CMakeFiles/queue.dir/linklibs.rsp
queue.exe: CMakeFiles/queue.dir/objects1.rsp
queue.exe: CMakeFiles/queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\workspace\C\dataStructure\LinearTable\queue\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable queue.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\queue.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/queue.dir/build: queue.exe

.PHONY : CMakeFiles/queue.dir/build

CMakeFiles/queue.dir/requires: CMakeFiles/queue.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/queue.dir/requires

CMakeFiles/queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\queue.dir\cmake_clean.cmake
.PHONY : CMakeFiles/queue.dir/clean

CMakeFiles/queue.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\workspace\C\dataStructure\LinearTable\queue E:\workspace\C\dataStructure\LinearTable\queue E:\workspace\C\dataStructure\LinearTable\queue\cmake-build-debug E:\workspace\C\dataStructure\LinearTable\queue\cmake-build-debug E:\workspace\C\dataStructure\LinearTable\queue\cmake-build-debug\CMakeFiles\queue.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/queue.dir/depend

