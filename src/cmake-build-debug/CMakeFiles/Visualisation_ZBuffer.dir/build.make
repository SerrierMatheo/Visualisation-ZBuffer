# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Visualisation_ZBuffer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Visualisation_ZBuffer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Visualisation_ZBuffer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Visualisation_ZBuffer.dir/flags.make

CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/flags.make
CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.o: /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Face.cpp
CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.o -MF CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.o.d -o CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.o -c /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Face.cpp

CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Face.cpp > CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.i

CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Face.cpp -o CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.s

CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/flags.make
CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.o: /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/PlyObject3D.cpp
CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.o -MF CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.o.d -o CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.o -c /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/PlyObject3D.cpp

CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/PlyObject3D.cpp > CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.i

CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/PlyObject3D.cpp -o CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.s

CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/flags.make
CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.o: /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Vertex.cpp
CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.o -MF CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.o.d -o CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.o -c /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Vertex.cpp

CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Vertex.cpp > CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.i

CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Vertex.cpp -o CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.s

CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/flags.make
CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.o: /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/main.cpp
CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.o -MF CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.o.d -o CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.o -c /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/main.cpp

CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/main.cpp > CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.i

CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/main.cpp -o CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.s

CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/flags.make
CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.o: /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Object3D.cpp
CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.o -MF CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.o.d -o CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.o -c /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Object3D.cpp

CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Object3D.cpp > CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.i

CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Object3D.cpp -o CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.s

CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/flags.make
CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.o: /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Vertex.cpp
CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.o -MF CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.o.d -o CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.o -c /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Vertex.cpp

CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Vertex.cpp > CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.i

CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Vertex.cpp -o CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.s

CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/flags.make
CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.o: /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Face.cpp
CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.o: CMakeFiles/Visualisation_ZBuffer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.o -MF CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.o.d -o CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.o -c /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Face.cpp

CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Face.cpp > CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.i

CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/Code_Exemple_SDL/Face.cpp -o CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.s

# Object files for target Visualisation_ZBuffer
Visualisation_ZBuffer_OBJECTS = \
"CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.o" \
"CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.o" \
"CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.o" \
"CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.o" \
"CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.o" \
"CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.o" \
"CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.o"

# External object files for target Visualisation_ZBuffer
Visualisation_ZBuffer_EXTERNAL_OBJECTS =

Visualisation_ZBuffer: CMakeFiles/Visualisation_ZBuffer.dir/Face.cpp.o
Visualisation_ZBuffer: CMakeFiles/Visualisation_ZBuffer.dir/PlyObject3D.cpp.o
Visualisation_ZBuffer: CMakeFiles/Visualisation_ZBuffer.dir/Vertex.cpp.o
Visualisation_ZBuffer: CMakeFiles/Visualisation_ZBuffer.dir/main.cpp.o
Visualisation_ZBuffer: CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Object3D.cpp.o
Visualisation_ZBuffer: CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Vertex.cpp.o
Visualisation_ZBuffer: CMakeFiles/Visualisation_ZBuffer.dir/Code_Exemple_SDL/Face.cpp.o
Visualisation_ZBuffer: CMakeFiles/Visualisation_ZBuffer.dir/build.make
Visualisation_ZBuffer: /usr/local/lib/libSDLmain.a
Visualisation_ZBuffer: /usr/local/lib/libSDL.dylib
Visualisation_ZBuffer: CMakeFiles/Visualisation_ZBuffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Visualisation_ZBuffer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Visualisation_ZBuffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Visualisation_ZBuffer.dir/build: Visualisation_ZBuffer
.PHONY : CMakeFiles/Visualisation_ZBuffer.dir/build

CMakeFiles/Visualisation_ZBuffer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Visualisation_ZBuffer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Visualisation_ZBuffer.dir/clean

CMakeFiles/Visualisation_ZBuffer.dir/depend:
	cd /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug /Users/stages/Documents/Matheo/Visualisation-ZBuffer/src/cmake-build-debug/CMakeFiles/Visualisation_ZBuffer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Visualisation_ZBuffer.dir/depend

