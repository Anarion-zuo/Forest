# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\AI\Forest\cppForest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\AI\Forest\cppForest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cppForest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cppForest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppForest.dir/flags.make

CMakeFiles/cppForest.dir/main.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cppForest.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\main.cpp.obj -c D:\AI\Forest\cppForest\main.cpp

CMakeFiles/cppForest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\main.cpp > CMakeFiles\cppForest.dir\main.cpp.i

CMakeFiles/cppForest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\main.cpp -o CMakeFiles\cppForest.dir\main.cpp.s

CMakeFiles/cppForest.dir/cgNode/cgNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/cgNode.cpp.obj: ../cgNode/cgNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cppForest.dir/cgNode/cgNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\cgNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\cgNode.cpp

CMakeFiles/cppForest.dir/cgNode/cgNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/cgNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\cgNode.cpp > CMakeFiles\cppForest.dir\cgNode\cgNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/cgNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/cgNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\cgNode.cpp -o CMakeFiles\cppForest.dir\cgNode\cgNode.cpp.s

CMakeFiles/cppForest.dir/Garbage_Bin.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/Garbage_Bin.cpp.obj: ../Garbage_Bin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cppForest.dir/Garbage_Bin.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\Garbage_Bin.cpp.obj -c D:\AI\Forest\cppForest\Garbage_Bin.cpp

CMakeFiles/cppForest.dir/Garbage_Bin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/Garbage_Bin.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\Garbage_Bin.cpp > CMakeFiles\cppForest.dir\Garbage_Bin.cpp.i

CMakeFiles/cppForest.dir/Garbage_Bin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/Garbage_Bin.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\Garbage_Bin.cpp -o CMakeFiles\cppForest.dir\Garbage_Bin.cpp.s

CMakeFiles/cppForest.dir/cgNode/addNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/addNode.cpp.obj: ../cgNode/addNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cppForest.dir/cgNode/addNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\addNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\addNode.cpp

CMakeFiles/cppForest.dir/cgNode/addNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/addNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\addNode.cpp > CMakeFiles\cppForest.dir\cgNode\addNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/addNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/addNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\addNode.cpp -o CMakeFiles\cppForest.dir\cgNode\addNode.cpp.s

CMakeFiles/cppForest.dir/cgNode/mulNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/mulNode.cpp.obj: ../cgNode/mulNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cppForest.dir/cgNode/mulNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\mulNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\mulNode.cpp

CMakeFiles/cppForest.dir/cgNode/mulNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/mulNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\mulNode.cpp > CMakeFiles\cppForest.dir\cgNode\mulNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/mulNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/mulNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\mulNode.cpp -o CMakeFiles\cppForest.dir\cgNode\mulNode.cpp.s

CMakeFiles/cppForest.dir/cgNode/divNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/divNode.cpp.obj: ../cgNode/divNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cppForest.dir/cgNode/divNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\divNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\divNode.cpp

CMakeFiles/cppForest.dir/cgNode/divNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/divNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\divNode.cpp > CMakeFiles\cppForest.dir\cgNode\divNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/divNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/divNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\divNode.cpp -o CMakeFiles\cppForest.dir\cgNode\divNode.cpp.s

CMakeFiles/cppForest.dir/cgNode/subNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/subNode.cpp.obj: ../cgNode/subNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cppForest.dir/cgNode/subNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\subNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\subNode.cpp

CMakeFiles/cppForest.dir/cgNode/subNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/subNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\subNode.cpp > CMakeFiles\cppForest.dir\cgNode\subNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/subNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/subNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\subNode.cpp -o CMakeFiles\cppForest.dir\cgNode\subNode.cpp.s

CMakeFiles/cppForest.dir/cgNode/constNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/constNode.cpp.obj: ../cgNode/constNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cppForest.dir/cgNode/constNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\constNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\constNode.cpp

CMakeFiles/cppForest.dir/cgNode/constNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/constNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\constNode.cpp > CMakeFiles\cppForest.dir\cgNode\constNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/constNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/constNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\constNode.cpp -o CMakeFiles\cppForest.dir\cgNode\constNode.cpp.s

CMakeFiles/cppForest.dir/cgNode/varNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/varNode.cpp.obj: ../cgNode/varNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/cppForest.dir/cgNode/varNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\varNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\varNode.cpp

CMakeFiles/cppForest.dir/cgNode/varNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/varNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\varNode.cpp > CMakeFiles\cppForest.dir\cgNode\varNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/varNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/varNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\varNode.cpp -o CMakeFiles\cppForest.dir\cgNode\varNode.cpp.s

CMakeFiles/cppForest.dir/cg/cg.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cg/cg.cpp.obj: ../cg/cg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/cppForest.dir/cg/cg.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cg\cg.cpp.obj -c D:\AI\Forest\cppForest\cg\cg.cpp

CMakeFiles/cppForest.dir/cg/cg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cg/cg.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cg\cg.cpp > CMakeFiles\cppForest.dir\cg\cg.cpp.i

CMakeFiles/cppForest.dir/cg/cg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cg/cg.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cg\cg.cpp -o CMakeFiles\cppForest.dir\cg\cg.cpp.s

CMakeFiles/cppForest.dir/cgNode/expNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/expNode.cpp.obj: ../cgNode/expNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/cppForest.dir/cgNode/expNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\expNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\expNode.cpp

CMakeFiles/cppForest.dir/cgNode/expNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/expNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\expNode.cpp > CMakeFiles\cppForest.dir\cgNode\expNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/expNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/expNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\expNode.cpp -o CMakeFiles\cppForest.dir\cgNode\expNode.cpp.s

CMakeFiles/cppForest.dir/cgNode/monopNodes/lnNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/monopNodes/lnNode.cpp.obj: ../cgNode/monopNodes/lnNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/cppForest.dir/cgNode/monopNodes/lnNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\monopNodes\lnNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\monopNodes\lnNode.cpp

CMakeFiles/cppForest.dir/cgNode/monopNodes/lnNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/monopNodes/lnNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\monopNodes\lnNode.cpp > CMakeFiles\cppForest.dir\cgNode\monopNodes\lnNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/monopNodes/lnNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/monopNodes/lnNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\monopNodes\lnNode.cpp -o CMakeFiles\cppForest.dir\cgNode\monopNodes\lnNode.cpp.s

CMakeFiles/cppForest.dir/cgNode/monopNodes/monopNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/monopNodes/monopNode.cpp.obj: ../cgNode/monopNodes/monopNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/cppForest.dir/cgNode/monopNodes/monopNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\monopNodes\monopNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\monopNodes\monopNode.cpp

CMakeFiles/cppForest.dir/cgNode/monopNodes/monopNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/monopNodes/monopNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\monopNodes\monopNode.cpp > CMakeFiles\cppForest.dir\cgNode\monopNodes\monopNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/monopNodes/monopNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/monopNodes/monopNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\monopNodes\monopNode.cpp -o CMakeFiles\cppForest.dir\cgNode\monopNodes\monopNode.cpp.s

CMakeFiles/cppForest.dir/cgNode/monopNodes/sinNode.cpp.obj: CMakeFiles/cppForest.dir/flags.make
CMakeFiles/cppForest.dir/cgNode/monopNodes/sinNode.cpp.obj: ../cgNode/monopNodes/sinNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/cppForest.dir/cgNode/monopNodes/sinNode.cpp.obj"
	D:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cppForest.dir\cgNode\monopNodes\sinNode.cpp.obj -c D:\AI\Forest\cppForest\cgNode\monopNodes\sinNode.cpp

CMakeFiles/cppForest.dir/cgNode/monopNodes/sinNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppForest.dir/cgNode/monopNodes/sinNode.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\AI\Forest\cppForest\cgNode\monopNodes\sinNode.cpp > CMakeFiles\cppForest.dir\cgNode\monopNodes\sinNode.cpp.i

CMakeFiles/cppForest.dir/cgNode/monopNodes/sinNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppForest.dir/cgNode/monopNodes/sinNode.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\AI\Forest\cppForest\cgNode\monopNodes\sinNode.cpp -o CMakeFiles\cppForest.dir\cgNode\monopNodes\sinNode.cpp.s

# Object files for target cppForest
cppForest_OBJECTS = \
"CMakeFiles/cppForest.dir/main.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/cgNode.cpp.obj" \
"CMakeFiles/cppForest.dir/Garbage_Bin.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/addNode.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/mulNode.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/divNode.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/subNode.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/constNode.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/varNode.cpp.obj" \
"CMakeFiles/cppForest.dir/cg/cg.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/expNode.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/monopNodes/lnNode.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/monopNodes/monopNode.cpp.obj" \
"CMakeFiles/cppForest.dir/cgNode/monopNodes/sinNode.cpp.obj"

# External object files for target cppForest
cppForest_EXTERNAL_OBJECTS =

cppForest.exe: CMakeFiles/cppForest.dir/main.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/cgNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/Garbage_Bin.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/addNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/mulNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/divNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/subNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/constNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/varNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cg/cg.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/expNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/monopNodes/lnNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/monopNodes/monopNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/cgNode/monopNodes/sinNode.cpp.obj
cppForest.exe: CMakeFiles/cppForest.dir/build.make
cppForest.exe: CMakeFiles/cppForest.dir/linklibs.rsp
cppForest.exe: CMakeFiles/cppForest.dir/objects1.rsp
cppForest.exe: CMakeFiles/cppForest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable cppForest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cppForest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppForest.dir/build: cppForest.exe

.PHONY : CMakeFiles/cppForest.dir/build

CMakeFiles/cppForest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cppForest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cppForest.dir/clean

CMakeFiles/cppForest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\AI\Forest\cppForest D:\AI\Forest\cppForest D:\AI\Forest\cppForest\cmake-build-debug D:\AI\Forest\cppForest\cmake-build-debug D:\AI\Forest\cppForest\cmake-build-debug\CMakeFiles\cppForest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cppForest.dir/depend

