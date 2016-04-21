project(gesutre_build C CXX)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV 3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

cmake_policy(SET CMP0015 NEW)
link_directories(.)
set(GESTURE_LIB
	libgesture.so
)

set(EXAMPLE_SRC
	example.cpp
)

add_executable(gesture_example ${EXAMPLE_SRC})
set_property(TARGET gesture_example PROPERTY CXX_STANDARD 11)

target_link_libraries(gesture_example ${GESTURE_LIB} ${OpenCV_LIBRARIES})
