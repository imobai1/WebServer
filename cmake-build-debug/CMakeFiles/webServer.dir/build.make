# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/webServe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/webServe/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/webServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/webServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/webServer.dir/flags.make

CMakeFiles/webServer.dir/main.cpp.o: CMakeFiles/webServer.dir/flags.make
CMakeFiles/webServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/webServe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/webServer.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webServer.dir/main.cpp.o -c /home/webServe/main.cpp

CMakeFiles/webServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webServer.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/webServe/main.cpp > CMakeFiles/webServer.dir/main.cpp.i

CMakeFiles/webServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webServer.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/webServe/main.cpp -o CMakeFiles/webServer.dir/main.cpp.s

CMakeFiles/webServer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/webServer.dir/main.cpp.o.requires

CMakeFiles/webServer.dir/main.cpp.o.provides: CMakeFiles/webServer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/webServer.dir/build.make CMakeFiles/webServer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/webServer.dir/main.cpp.o.provides

CMakeFiles/webServer.dir/main.cpp.o.provides.build: CMakeFiles/webServer.dir/main.cpp.o


CMakeFiles/webServer.dir/http/httpConnection.cpp.o: CMakeFiles/webServer.dir/flags.make
CMakeFiles/webServer.dir/http/httpConnection.cpp.o: ../http/httpConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/webServe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/webServer.dir/http/httpConnection.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webServer.dir/http/httpConnection.cpp.o -c /home/webServe/http/httpConnection.cpp

CMakeFiles/webServer.dir/http/httpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webServer.dir/http/httpConnection.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/webServe/http/httpConnection.cpp > CMakeFiles/webServer.dir/http/httpConnection.cpp.i

CMakeFiles/webServer.dir/http/httpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webServer.dir/http/httpConnection.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/webServe/http/httpConnection.cpp -o CMakeFiles/webServer.dir/http/httpConnection.cpp.s

CMakeFiles/webServer.dir/http/httpConnection.cpp.o.requires:

.PHONY : CMakeFiles/webServer.dir/http/httpConnection.cpp.o.requires

CMakeFiles/webServer.dir/http/httpConnection.cpp.o.provides: CMakeFiles/webServer.dir/http/httpConnection.cpp.o.requires
	$(MAKE) -f CMakeFiles/webServer.dir/build.make CMakeFiles/webServer.dir/http/httpConnection.cpp.o.provides.build
.PHONY : CMakeFiles/webServer.dir/http/httpConnection.cpp.o.provides

CMakeFiles/webServer.dir/http/httpConnection.cpp.o.provides.build: CMakeFiles/webServer.dir/http/httpConnection.cpp.o


CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o: CMakeFiles/webServer.dir/flags.make
CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o: ../CGImysql/sqlConnetionPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/webServe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o -c /home/webServe/CGImysql/sqlConnetionPool.cpp

CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/webServe/CGImysql/sqlConnetionPool.cpp > CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.i

CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/webServe/CGImysql/sqlConnetionPool.cpp -o CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.s

CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o.requires:

.PHONY : CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o.requires

CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o.provides: CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o.requires
	$(MAKE) -f CMakeFiles/webServer.dir/build.make CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o.provides.build
.PHONY : CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o.provides

CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o.provides.build: CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o


CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o: CMakeFiles/webServer.dir/flags.make
CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o: ../Thread_synchronization_mechanism/signal/sem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/webServe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o -c /home/webServe/Thread_synchronization_mechanism/signal/sem.cpp

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/webServe/Thread_synchronization_mechanism/signal/sem.cpp > CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.i

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/webServe/Thread_synchronization_mechanism/signal/sem.cpp -o CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.s

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o.requires:

.PHONY : CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o.requires

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o.provides: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o.requires
	$(MAKE) -f CMakeFiles/webServer.dir/build.make CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o.provides.build
.PHONY : CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o.provides

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o.provides.build: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o


CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o: CMakeFiles/webServer.dir/flags.make
CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o: ../Thread_synchronization_mechanism/condition/condition.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/webServe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o -c /home/webServe/Thread_synchronization_mechanism/condition/condition.cpp

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/webServe/Thread_synchronization_mechanism/condition/condition.cpp > CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.i

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/webServe/Thread_synchronization_mechanism/condition/condition.cpp -o CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.s

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o.requires:

.PHONY : CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o.requires

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o.provides: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o.requires
	$(MAKE) -f CMakeFiles/webServer.dir/build.make CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o.provides.build
.PHONY : CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o.provides

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o.provides.build: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o


CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o: CMakeFiles/webServer.dir/flags.make
CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o: ../Thread_synchronization_mechanism/locker/locker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/webServe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o -c /home/webServe/Thread_synchronization_mechanism/locker/locker.cpp

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/webServe/Thread_synchronization_mechanism/locker/locker.cpp > CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.i

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/webServe/Thread_synchronization_mechanism/locker/locker.cpp -o CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.s

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o.requires:

.PHONY : CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o.requires

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o.provides: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o.requires
	$(MAKE) -f CMakeFiles/webServer.dir/build.make CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o.provides.build
.PHONY : CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o.provides

CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o.provides.build: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o


CMakeFiles/webServer.dir/log/log.cpp.o: CMakeFiles/webServer.dir/flags.make
CMakeFiles/webServer.dir/log/log.cpp.o: ../log/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/webServe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/webServer.dir/log/log.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webServer.dir/log/log.cpp.o -c /home/webServe/log/log.cpp

CMakeFiles/webServer.dir/log/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webServer.dir/log/log.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/webServe/log/log.cpp > CMakeFiles/webServer.dir/log/log.cpp.i

CMakeFiles/webServer.dir/log/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webServer.dir/log/log.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/webServe/log/log.cpp -o CMakeFiles/webServer.dir/log/log.cpp.s

CMakeFiles/webServer.dir/log/log.cpp.o.requires:

.PHONY : CMakeFiles/webServer.dir/log/log.cpp.o.requires

CMakeFiles/webServer.dir/log/log.cpp.o.provides: CMakeFiles/webServer.dir/log/log.cpp.o.requires
	$(MAKE) -f CMakeFiles/webServer.dir/build.make CMakeFiles/webServer.dir/log/log.cpp.o.provides.build
.PHONY : CMakeFiles/webServer.dir/log/log.cpp.o.provides

CMakeFiles/webServer.dir/log/log.cpp.o.provides.build: CMakeFiles/webServer.dir/log/log.cpp.o


# Object files for target webServer
webServer_OBJECTS = \
"CMakeFiles/webServer.dir/main.cpp.o" \
"CMakeFiles/webServer.dir/http/httpConnection.cpp.o" \
"CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o" \
"CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o" \
"CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o" \
"CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o" \
"CMakeFiles/webServer.dir/log/log.cpp.o"

# External object files for target webServer
webServer_EXTERNAL_OBJECTS =

webServer: CMakeFiles/webServer.dir/main.cpp.o
webServer: CMakeFiles/webServer.dir/http/httpConnection.cpp.o
webServer: CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o
webServer: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o
webServer: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o
webServer: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o
webServer: CMakeFiles/webServer.dir/log/log.cpp.o
webServer: CMakeFiles/webServer.dir/build.make
webServer: CMakeFiles/webServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/webServe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable webServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/webServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/webServer.dir/build: webServer

.PHONY : CMakeFiles/webServer.dir/build

CMakeFiles/webServer.dir/requires: CMakeFiles/webServer.dir/main.cpp.o.requires
CMakeFiles/webServer.dir/requires: CMakeFiles/webServer.dir/http/httpConnection.cpp.o.requires
CMakeFiles/webServer.dir/requires: CMakeFiles/webServer.dir/CGImysql/sqlConnetionPool.cpp.o.requires
CMakeFiles/webServer.dir/requires: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/signal/sem.cpp.o.requires
CMakeFiles/webServer.dir/requires: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/condition/condition.cpp.o.requires
CMakeFiles/webServer.dir/requires: CMakeFiles/webServer.dir/Thread_synchronization_mechanism/locker/locker.cpp.o.requires
CMakeFiles/webServer.dir/requires: CMakeFiles/webServer.dir/log/log.cpp.o.requires

.PHONY : CMakeFiles/webServer.dir/requires

CMakeFiles/webServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/webServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/webServer.dir/clean

CMakeFiles/webServer.dir/depend:
	cd /home/webServe/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/webServe /home/webServe /home/webServe/cmake-build-debug /home/webServe/cmake-build-debug /home/webServe/cmake-build-debug/CMakeFiles/webServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/webServer.dir/depend

