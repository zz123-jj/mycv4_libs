cmake_minimum_required(VERSION 3.10)

project(Myopencv4)

find_package(OpenCV REQUIRED)
add_library(drawing src/drawing.cpp)
target_include_directories(drawing PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(drawing ${OpenCV_LIBS})

add_executable(demo src/main.cpp)
target_link_libraries(demo drawing ${OpenCV_LIBS})