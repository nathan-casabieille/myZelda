cmake_minimum_required(VERSION 3.0) 

project(Zelda VERSION 1.0)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/cmake/CSFML/include)
link_directories(${CMAKE_SOURCE_DIR}/cmake/CSFML/lib/msvc)

# add include directories
include_directories(include)

# add the source directories
set(SRCS
    src/main.c
    src/object/create_object.c
    src/object/destroy_object.c
    src/object/draw_object.c
    src/camera/apply_camera.c
    src/camera/create_camera.c
    src/camera/destroy_camera.c
    src/camera/update_camera.c
)
# add the executable
add_executable(Zelda ${SRCS})

target_link_libraries(Zelda sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(Zelda csfml-graphics csfml-window csfml-system csfml-audio)