# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /opt/cmake-3.23.1-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.23.1-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/valentin/Bureau/GitHub/CleanCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valentin/Bureau/GitHub/CleanCode/build

# Include any dependencies generated for this target.
include CMakeFiles/CleanCode.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CleanCode.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CleanCode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CleanCode.dir/flags.make

CMakeFiles/CleanCode.dir/src/Boid.cpp.o: CMakeFiles/CleanCode.dir/flags.make
CMakeFiles/CleanCode.dir/src/Boid.cpp.o: ../src/Boid.cpp
CMakeFiles/CleanCode.dir/src/Boid.cpp.o: CMakeFiles/CleanCode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentin/Bureau/GitHub/CleanCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CleanCode.dir/src/Boid.cpp.o"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CleanCode.dir/src/Boid.cpp.o -MF CMakeFiles/CleanCode.dir/src/Boid.cpp.o.d -o CMakeFiles/CleanCode.dir/src/Boid.cpp.o -c /home/valentin/Bureau/GitHub/CleanCode/src/Boid.cpp

CMakeFiles/CleanCode.dir/src/Boid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CleanCode.dir/src/Boid.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/valentin/Bureau/GitHub/CleanCode/src/Boid.cpp > CMakeFiles/CleanCode.dir/src/Boid.cpp.i

CMakeFiles/CleanCode.dir/src/Boid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CleanCode.dir/src/Boid.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valentin/Bureau/GitHub/CleanCode/src/Boid.cpp -o CMakeFiles/CleanCode.dir/src/Boid.cpp.s

CMakeFiles/CleanCode.dir/src/Flock.cpp.o: CMakeFiles/CleanCode.dir/flags.make
CMakeFiles/CleanCode.dir/src/Flock.cpp.o: ../src/Flock.cpp
CMakeFiles/CleanCode.dir/src/Flock.cpp.o: CMakeFiles/CleanCode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentin/Bureau/GitHub/CleanCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CleanCode.dir/src/Flock.cpp.o"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CleanCode.dir/src/Flock.cpp.o -MF CMakeFiles/CleanCode.dir/src/Flock.cpp.o.d -o CMakeFiles/CleanCode.dir/src/Flock.cpp.o -c /home/valentin/Bureau/GitHub/CleanCode/src/Flock.cpp

CMakeFiles/CleanCode.dir/src/Flock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CleanCode.dir/src/Flock.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/valentin/Bureau/GitHub/CleanCode/src/Flock.cpp > CMakeFiles/CleanCode.dir/src/Flock.cpp.i

CMakeFiles/CleanCode.dir/src/Flock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CleanCode.dir/src/Flock.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valentin/Bureau/GitHub/CleanCode/src/Flock.cpp -o CMakeFiles/CleanCode.dir/src/Flock.cpp.s

CMakeFiles/CleanCode.dir/src/main.cpp.o: CMakeFiles/CleanCode.dir/flags.make
CMakeFiles/CleanCode.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/CleanCode.dir/src/main.cpp.o: CMakeFiles/CleanCode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentin/Bureau/GitHub/CleanCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CleanCode.dir/src/main.cpp.o"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CleanCode.dir/src/main.cpp.o -MF CMakeFiles/CleanCode.dir/src/main.cpp.o.d -o CMakeFiles/CleanCode.dir/src/main.cpp.o -c /home/valentin/Bureau/GitHub/CleanCode/src/main.cpp

CMakeFiles/CleanCode.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CleanCode.dir/src/main.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/valentin/Bureau/GitHub/CleanCode/src/main.cpp > CMakeFiles/CleanCode.dir/src/main.cpp.i

CMakeFiles/CleanCode.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CleanCode.dir/src/main.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valentin/Bureau/GitHub/CleanCode/src/main.cpp -o CMakeFiles/CleanCode.dir/src/main.cpp.s

CMakeFiles/CleanCode.dir/src/random.cpp.o: CMakeFiles/CleanCode.dir/flags.make
CMakeFiles/CleanCode.dir/src/random.cpp.o: ../src/random.cpp
CMakeFiles/CleanCode.dir/src/random.cpp.o: CMakeFiles/CleanCode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentin/Bureau/GitHub/CleanCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CleanCode.dir/src/random.cpp.o"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CleanCode.dir/src/random.cpp.o -MF CMakeFiles/CleanCode.dir/src/random.cpp.o.d -o CMakeFiles/CleanCode.dir/src/random.cpp.o -c /home/valentin/Bureau/GitHub/CleanCode/src/random.cpp

CMakeFiles/CleanCode.dir/src/random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CleanCode.dir/src/random.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/valentin/Bureau/GitHub/CleanCode/src/random.cpp > CMakeFiles/CleanCode.dir/src/random.cpp.i

CMakeFiles/CleanCode.dir/src/random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CleanCode.dir/src/random.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valentin/Bureau/GitHub/CleanCode/src/random.cpp -o CMakeFiles/CleanCode.dir/src/random.cpp.s

CMakeFiles/CleanCode.dir/src/render.cpp.o: CMakeFiles/CleanCode.dir/flags.make
CMakeFiles/CleanCode.dir/src/render.cpp.o: ../src/render.cpp
CMakeFiles/CleanCode.dir/src/render.cpp.o: CMakeFiles/CleanCode.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentin/Bureau/GitHub/CleanCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CleanCode.dir/src/render.cpp.o"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CleanCode.dir/src/render.cpp.o -MF CMakeFiles/CleanCode.dir/src/render.cpp.o.d -o CMakeFiles/CleanCode.dir/src/render.cpp.o -c /home/valentin/Bureau/GitHub/CleanCode/src/render.cpp

CMakeFiles/CleanCode.dir/src/render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CleanCode.dir/src/render.cpp.i"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/valentin/Bureau/GitHub/CleanCode/src/render.cpp > CMakeFiles/CleanCode.dir/src/render.cpp.i

CMakeFiles/CleanCode.dir/src/render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CleanCode.dir/src/render.cpp.s"
	/usr/bin/clang++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/valentin/Bureau/GitHub/CleanCode/src/render.cpp -o CMakeFiles/CleanCode.dir/src/render.cpp.s

# Object files for target CleanCode
CleanCode_OBJECTS = \
"CMakeFiles/CleanCode.dir/src/Boid.cpp.o" \
"CMakeFiles/CleanCode.dir/src/Flock.cpp.o" \
"CMakeFiles/CleanCode.dir/src/main.cpp.o" \
"CMakeFiles/CleanCode.dir/src/random.cpp.o" \
"CMakeFiles/CleanCode.dir/src/render.cpp.o"

# External object files for target CleanCode
CleanCode_EXTERNAL_OBJECTS =

../bin/Debug/CleanCode: CMakeFiles/CleanCode.dir/src/Boid.cpp.o
../bin/Debug/CleanCode: CMakeFiles/CleanCode.dir/src/Flock.cpp.o
../bin/Debug/CleanCode: CMakeFiles/CleanCode.dir/src/main.cpp.o
../bin/Debug/CleanCode: CMakeFiles/CleanCode.dir/src/random.cpp.o
../bin/Debug/CleanCode: CMakeFiles/CleanCode.dir/src/render.cpp.o
../bin/Debug/CleanCode: CMakeFiles/CleanCode.dir/build.make
../bin/Debug/CleanCode: p6/libp6.a
../bin/Debug/CleanCode: p6/third-party/glpp-extended/libglpp-extended.a
../bin/Debug/CleanCode: p6/third-party/glpp-extended/lib/glpp/libglpp.a
../bin/Debug/CleanCode: p6/third-party/glpp-extended/lib/glpp/libglad.a
../bin/Debug/CleanCode: p6/third-party/img/libimg.a
../bin/Debug/CleanCode: p6/third-party/img/libstb_image.a
../bin/Debug/CleanCode: p6/third-party/exe_path/libexe_path.a
../bin/Debug/CleanCode: p6/third-party/imgui/libImGui.a
../bin/Debug/CleanCode: p6/third-party/glfw/src/libglfw3.a
../bin/Debug/CleanCode: /usr/lib/x86_64-linux-gnu/librt.so
../bin/Debug/CleanCode: /usr/lib/x86_64-linux-gnu/libm.so
../bin/Debug/CleanCode: CMakeFiles/CleanCode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/valentin/Bureau/GitHub/CleanCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../bin/Debug/CleanCode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CleanCode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CleanCode.dir/build: ../bin/Debug/CleanCode
.PHONY : CMakeFiles/CleanCode.dir/build

CMakeFiles/CleanCode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CleanCode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CleanCode.dir/clean

CMakeFiles/CleanCode.dir/depend:
	cd /home/valentin/Bureau/GitHub/CleanCode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/valentin/Bureau/GitHub/CleanCode /home/valentin/Bureau/GitHub/CleanCode /home/valentin/Bureau/GitHub/CleanCode/build /home/valentin/Bureau/GitHub/CleanCode/build /home/valentin/Bureau/GitHub/CleanCode/build/CMakeFiles/CleanCode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CleanCode.dir/depend

