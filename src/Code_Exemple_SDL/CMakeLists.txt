project(Infographie)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

FIND_PACKAGE(SDL REQUIRED)
if ( SDL_FOUND )
    message(SDL_FOUND >>>>> ${SDL_INCLUDE_DIRS})
endif()
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIRS})
LINK_DIRECTORIES(${SDL_LIBRARY_DIRS})

add_definitions(-g)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL_LIBRARIES})