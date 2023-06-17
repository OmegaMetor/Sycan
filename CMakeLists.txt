cmake_minimum_required(VERSION 3.0.0)
project(Sycan VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Sycan 
src/Sycan.cpp
src/Object.cpp
)

include_directories(
    lib/
)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

if(TARGET SDL2::SDL2main)
    target_link_libraries(Sycan PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(Sycan PRIVATE SDL2::SDL2)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
