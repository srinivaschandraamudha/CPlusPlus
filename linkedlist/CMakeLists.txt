cmake_minimum_required(VERSION 3.22.1)

# set the project name
project("list")

# set source files
set(SOURCE_FILES
    src/main.cpp
    src/list.cpp)

#set the output directory for the binary.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)

# set the project name
project("test")

# set source files
set(SOURCE_FILES
    test/test.cpp
    src/list.cpp)

#set the test directory for the test binary.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test")

# add the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
