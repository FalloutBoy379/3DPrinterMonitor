# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build"

# Include any dependencies generated for this target.
include modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/compiler_depend.make

# Include the progress variables for this target.
include modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/progress.make

# Include the compile flags for this target's objects.
include modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/flags.make

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.o: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.o: /home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test\ Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_jpeg.cpp
modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.o: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.o"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.o -MF CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.o.d -o CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.o -c "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_jpeg.cpp"

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.i"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_jpeg.cpp" > CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.i

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.s"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_jpeg.cpp" -o CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.s

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.o: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.o: /home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test\ Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_main.cpp
modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.o: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.o"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.o -MF CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.o.d -o CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.o -c "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_main.cpp"

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.i"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_main.cpp" > CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.i

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.s"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_main.cpp" -o CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.s

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.o: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/flags.make
modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.o: /home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test\ Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_png.cpp
modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.o: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.o"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.o -MF CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.o.d -o CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.o -c "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_png.cpp"

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.i"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_png.cpp" > CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.i

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.s"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs/perf/perf_png.cpp" -o CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.s

# Object files for target opencv_perf_imgcodecs
opencv_perf_imgcodecs_OBJECTS = \
"CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.o" \
"CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.o" \
"CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.o"

# External object files for target opencv_perf_imgcodecs
opencv_perf_imgcodecs_EXTERNAL_OBJECTS =

bin/opencv_perf_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_jpeg.cpp.o
bin/opencv_perf_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_main.cpp.o
bin/opencv_perf_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/perf/perf_png.cpp.o
bin/opencv_perf_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/build.make
bin/opencv_perf_imgcodecs: lib/libopencv_ts.a
bin/opencv_perf_imgcodecs: lib/libopencv_highgui.so.4.9.0
bin/opencv_perf_imgcodecs: 3rdparty/lib/libippiw.a
bin/opencv_perf_imgcodecs: 3rdparty/ippicv/ippicv_lnx/icv/lib/intel64/libippicv.a
bin/opencv_perf_imgcodecs: lib/libopencv_videoio.so.4.9.0
bin/opencv_perf_imgcodecs: lib/libopencv_imgcodecs.so.4.9.0
bin/opencv_perf_imgcodecs: lib/libopencv_imgproc.so.4.9.0
bin/opencv_perf_imgcodecs: lib/libopencv_core.so.4.9.0
bin/opencv_perf_imgcodecs: modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../bin/opencv_perf_imgcodecs"
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_perf_imgcodecs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/build: bin/opencv_perf_imgcodecs
.PHONY : modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/build

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/clean:
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" && $(CMAKE_COMMAND) -P CMakeFiles/opencv_perf_imgcodecs.dir/cmake_clean.cmake
.PHONY : modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/clean

modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/depend:
	cd "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x" "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgcodecs" "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build" "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs" "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/build/modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : modules/imgcodecs/CMakeFiles/opencv_perf_imgcodecs.dir/depend

