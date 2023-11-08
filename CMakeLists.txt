cmake_minimum_required(VERSION 3.0) 

project(Zelda VERSION 1.0)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/cmake/CSFML/include)
link_directories(${CMAKE_SOURCE_DIR}/cmake/CSFML/lib/msvc)

include_directories(include)

set(OBJECT_SRCS
    src/object/create_object.c
    src/object/destroy_object.c
    src/object/render_object.c
    src/object/move_object.c
    src/object/place_object.c
)

set(CAMERA_SRCS
    src/camera/apply_camera.c
    src/camera/create_camera.c
    src/camera/destroy_camera.c
    src/camera/update_camera.c
)

set(WORLD_SRCS
    src/world/create_world.c
    src/world/destroy_world.c
    src/world/render_world.c
    src/world/update_world.c
)

set(PLAYER_SRCS
    src/player/create_player.c
    src/player/destroy_player.c
    src/player/animate_player.c
    src/player/change_direction.c
)

set(PLAYER_CONTROLLER_SRCS
    src/player_controller/create_player_controller.c
    src/player_controller/handle_events.c
    src/player_controller/update_player_controller.c
)

set(ROOM_SCROLL_SRCS
    src/room_scroll/calculate_new_camera_position.c
    src/room_scroll/camera_reached_new_room.c
    src/room_scroll/continue_camera_scroll.c
    src/room_scroll/get_view_bounds.c
    src/room_scroll/move_player_with_camera.c
    src/room_scroll/player_reached_edge_of_screen.c
    src/room_scroll/position_player_after_scroll.c
    src/room_scroll/start_camera_scroll.c
    src/room_scroll/update_camera_for_room_scroll.c
)

set(HELPERS_SRCS
    src/helpers/normalize_vector.c
    src/helpers/vector_length.c
)

set(COLLISION_SRCS
    src/collision/can_move_to.c
    src/collision/move_object_if_possible.c
)

set(SRCS
    src/main.c
    ${OBJECT_SRCS}
    ${CAMERA_SRCS}
    ${WORLD_SRCS}
    ${PLAYER_SRCS}
    ${PLAYER_CONTROLLER_SRCS}
    ${ROOM_SCROLL_SRCS}
    ${HELPERS_SRCS}
    ${COLLISION_SRCS}
)

add_executable(Zelda ${SRCS})

target_link_libraries(Zelda sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(Zelda csfml-graphics csfml-window csfml-system csfml-audio)