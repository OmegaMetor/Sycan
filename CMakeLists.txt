cmake_minimum_required(VERSION 3.0.0)
project(Sycan VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Sycan 
src/Sycan.cpp
src/Object.cpp
src/TextureProvider.cpp
)

add_subdirectory(CommandLib)

include_directories(
    lib/
    CommandLib/include/
)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

# Find SDL2_image
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
find_package(SDL2_image REQUIRED)

find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

if(TARGET SDL2::SDL2main)
    target_link_libraries(Sycan PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(Sycan PRIVATE SDL2::SDL2 CommandLib SDL2_image)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
