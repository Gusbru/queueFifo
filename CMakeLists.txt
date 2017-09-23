project(queueFifo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Input.cpp Input.h Process.cpp Process.h Insert.cpp Insert.h Remove.cpp Remove.h Report.cpp Report.h Queues.cpp Queues.h Servers.cpp Servers.h main.cpp Output.cpp Output.h)
add_executable(queueFifo ${SOURCE_FILES})