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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/checkers-game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/checkers-game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/checkers-game.dir/flags.make

Debug/checkers-game/checkers-game.app/Contents/Resources/CinderApp.icns: /Users/jathinnama/Documents/Cinder/samples/data/CinderApp.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Debug/checkers-game/checkers-game.app/Contents/Resources/CinderApp.icns"
	$(CMAKE_COMMAND) -E copy /Users/jathinnama/Documents/Cinder/samples/data/CinderApp.icns Debug/checkers-game/checkers-game.app/Contents/Resources/CinderApp.icns

CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.o: CMakeFiles/checkers-game.dir/flags.make
CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.o: ../apps/cinder_app_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.o -c /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/apps/cinder_app_main.cc

CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/apps/cinder_app_main.cc > CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.i

CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/apps/cinder_app_main.cc -o CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.s

CMakeFiles/checkers-game.dir/src/player.cc.o: CMakeFiles/checkers-game.dir/flags.make
CMakeFiles/checkers-game.dir/src/player.cc.o: ../src/player.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/checkers-game.dir/src/player.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers-game.dir/src/player.cc.o -c /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/player.cc

CMakeFiles/checkers-game.dir/src/player.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers-game.dir/src/player.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/player.cc > CMakeFiles/checkers-game.dir/src/player.cc.i

CMakeFiles/checkers-game.dir/src/player.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers-game.dir/src/player.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/player.cc -o CMakeFiles/checkers-game.dir/src/player.cc.s

CMakeFiles/checkers-game.dir/src/game_board.cc.o: CMakeFiles/checkers-game.dir/flags.make
CMakeFiles/checkers-game.dir/src/game_board.cc.o: ../src/game_board.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/checkers-game.dir/src/game_board.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers-game.dir/src/game_board.cc.o -c /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/game_board.cc

CMakeFiles/checkers-game.dir/src/game_board.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers-game.dir/src/game_board.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/game_board.cc > CMakeFiles/checkers-game.dir/src/game_board.cc.i

CMakeFiles/checkers-game.dir/src/game_board.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers-game.dir/src/game_board.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/game_board.cc -o CMakeFiles/checkers-game.dir/src/game_board.cc.s

CMakeFiles/checkers-game.dir/src/game_piece.cc.o: CMakeFiles/checkers-game.dir/flags.make
CMakeFiles/checkers-game.dir/src/game_piece.cc.o: ../src/game_piece.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/checkers-game.dir/src/game_piece.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers-game.dir/src/game_piece.cc.o -c /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/game_piece.cc

CMakeFiles/checkers-game.dir/src/game_piece.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers-game.dir/src/game_piece.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/game_piece.cc > CMakeFiles/checkers-game.dir/src/game_piece.cc.i

CMakeFiles/checkers-game.dir/src/game_piece.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers-game.dir/src/game_piece.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/game_piece.cc -o CMakeFiles/checkers-game.dir/src/game_piece.cc.s

CMakeFiles/checkers-game.dir/src/square.cc.o: CMakeFiles/checkers-game.dir/flags.make
CMakeFiles/checkers-game.dir/src/square.cc.o: ../src/square.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/checkers-game.dir/src/square.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers-game.dir/src/square.cc.o -c /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/square.cc

CMakeFiles/checkers-game.dir/src/square.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers-game.dir/src/square.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/square.cc > CMakeFiles/checkers-game.dir/src/square.cc.i

CMakeFiles/checkers-game.dir/src/square.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers-game.dir/src/square.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/square.cc -o CMakeFiles/checkers-game.dir/src/square.cc.s

CMakeFiles/checkers-game.dir/src/sketchpad.cc.o: CMakeFiles/checkers-game.dir/flags.make
CMakeFiles/checkers-game.dir/src/sketchpad.cc.o: ../src/sketchpad.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/checkers-game.dir/src/sketchpad.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers-game.dir/src/sketchpad.cc.o -c /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/sketchpad.cc

CMakeFiles/checkers-game.dir/src/sketchpad.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers-game.dir/src/sketchpad.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/sketchpad.cc > CMakeFiles/checkers-game.dir/src/sketchpad.cc.i

CMakeFiles/checkers-game.dir/src/sketchpad.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers-game.dir/src/sketchpad.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/sketchpad.cc -o CMakeFiles/checkers-game.dir/src/sketchpad.cc.s

CMakeFiles/checkers-game.dir/src/checkers_app.cc.o: CMakeFiles/checkers-game.dir/flags.make
CMakeFiles/checkers-game.dir/src/checkers_app.cc.o: ../src/checkers_app.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/checkers-game.dir/src/checkers_app.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/checkers-game.dir/src/checkers_app.cc.o -c /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/checkers_app.cc

CMakeFiles/checkers-game.dir/src/checkers_app.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/checkers-game.dir/src/checkers_app.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/checkers_app.cc > CMakeFiles/checkers-game.dir/src/checkers_app.cc.i

CMakeFiles/checkers-game.dir/src/checkers_app.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/checkers-game.dir/src/checkers_app.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/src/checkers_app.cc -o CMakeFiles/checkers-game.dir/src/checkers_app.cc.s

# Object files for target checkers-game
checkers__game_OBJECTS = \
"CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.o" \
"CMakeFiles/checkers-game.dir/src/player.cc.o" \
"CMakeFiles/checkers-game.dir/src/game_board.cc.o" \
"CMakeFiles/checkers-game.dir/src/game_piece.cc.o" \
"CMakeFiles/checkers-game.dir/src/square.cc.o" \
"CMakeFiles/checkers-game.dir/src/sketchpad.cc.o" \
"CMakeFiles/checkers-game.dir/src/checkers_app.cc.o"

# External object files for target checkers-game
checkers__game_EXTERNAL_OBJECTS =

Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: CMakeFiles/checkers-game.dir/apps/cinder_app_main.cc.o
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: CMakeFiles/checkers-game.dir/src/player.cc.o
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: CMakeFiles/checkers-game.dir/src/game_board.cc.o
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: CMakeFiles/checkers-game.dir/src/game_piece.cc.o
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: CMakeFiles/checkers-game.dir/src/square.cc.o
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: CMakeFiles/checkers-game.dir/src/sketchpad.cc.o
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: CMakeFiles/checkers-game.dir/src/checkers_app.cc.o
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: CMakeFiles/checkers-game.dir/build.make
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: /Users/jathinnama/Documents/Cinder/lib/macosx/Debug/libcinder.a
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: /Users/jathinnama/Documents/Cinder/lib/macosx/libboost_system.a
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: /Users/jathinnama/Documents/Cinder/lib/macosx/libboost_filesystem.a
Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game: CMakeFiles/checkers-game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checkers-game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/checkers-game.dir/build: Debug/checkers-game/checkers-game.app/Contents/MacOS/checkers-game
CMakeFiles/checkers-game.dir/build: Debug/checkers-game/checkers-game.app/Contents/Resources/CinderApp.icns

.PHONY : CMakeFiles/checkers-game.dir/build

CMakeFiles/checkers-game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/checkers-game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/checkers-game.dir/clean

CMakeFiles/checkers-game.dir/depend:
	cd /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug /Users/jathinnama/Documents/Cinder/my-projects/final-project-jathinnm/cmake-build-debug/CMakeFiles/checkers-game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/checkers-game.dir/depend

