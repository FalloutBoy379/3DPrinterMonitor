cmake_minimum_required(VERSION 3.10)
project(MyProject)
project(Final)
project(Camera)
project(Converted)
project(Webcam_new)
project(Virtual)
project(Scaleup)

find_package(OpenCV REQUIRED)
add_executable(MyProject resize.cpp)
target_link_libraries(MyProject ${OpenCV_LIBS})

add_executable(Final compare.cpp)
target_link_libraries(Final ${OpenCV_LIBS})

add_executable(Camera webcam.cpp)
target_link_libraries(Camera ${OpenCV_LIBS})

add_executable(Converted imageconvert.cpp)
target_link_libraries(Converted ${OpenCV_LIBS})

add_executable(Webcam_new webcam2.cpp)
target_link_libraries(Webcam_new ${OpenCV_LIBS})

add_executable(Virtual virtual.cpp)
target_link_libraries(Virtual ${OpenCV_LIBS})

add_executable(Scaleup scale.cpp)
target_link_libraries(Scaleup ${OpenCV_LIBS})