project(queueFifo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp main.cpp Process.cpp Process.h Insert.cpp Insert.h)
add_executable(queueFifo ${SOURCE_FILES})