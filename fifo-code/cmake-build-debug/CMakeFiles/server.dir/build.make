# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /cygdrive/c/Users/wuviv/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/wuviv/AppData/Local/JetBrains/CLion2020.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/server.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/server.c.o: ../server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/server.dir/server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/server.c.o   -c "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/server.c"

CMakeFiles/server.dir/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/server.c" > CMakeFiles/server.dir/server.c.i

CMakeFiles/server.dir/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/server.c" -o CMakeFiles/server.dir/server.c.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/server.c.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

server.exe: CMakeFiles/server.dir/server.c.o
server.exe: CMakeFiles/server.dir/build.make
server.exe: libdc_verbose.a
server.exe: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable server.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: server.exe

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code" "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code" "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/cmake-build-debug" "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/cmake-build-debug" "/cygdrive/c/Users/wuviv/OneDrive/Documents/BCIT CST Fall 2020/COMP 4981/Lecture Code/fifo-code/cmake-build-debug/CMakeFiles/server.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

