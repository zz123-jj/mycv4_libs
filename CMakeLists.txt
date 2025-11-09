cmake_minimum_required(VERSION 3.10)

project(Myopencv4)

find_package(OpenCV REQUIRED)
add_library(mylib src/drawing.cpp
                 src/disp.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(mylib ${OpenCV_LIBS})

add_executable(demo src/main.cpp)
target_link_libraries(demo mylib ${OpenCV_LIBS})