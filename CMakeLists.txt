# cmake -S . -B build/ && cmake --build build

cmake_minimum_required(VERSION 3.30)
project(MovingAverageProject)
set(CMAKE_CXX_STANDARD 14)

set(WARNINGS_ON TRUE)
set(ELF_STATIC FALSE)
set(ELF_OPTIMIZED TRUE)
set(ELF_STRIPPED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(BUILD_PATH "${CMAKE_SOURCE_DIR}/build")

set(SOURCES
    src/main.cpp
)

if(NOT EXISTS ${BUILD_PATH})
    file(MAKE_DIRECTORY ${BUILD_PATH})
    message("'${BUILD_PATH}' created")
endif()

if(${WARNINGS_ON})
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
endif()

if(${ELF_STATIC})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()

if(${ELF_OPTIMIZED})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")
endif()

if(${ELF_STRIPPED})
    set(CMAKE_EXE_LINKER_FLAGS "-s")
endif()

add_executable(moving_average ${SOURCES})

message("CXX_FLAGS:              ${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_STANDARD:     c++${CMAKE_CXX_STANDARD}")
message("CMAKE_EXE_LINKER_FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")
message("SOURCES:                ${SOURCES}")
