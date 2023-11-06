#include "room_scroll.h"

void update_camera_for_room_scroll(world_t *world, float delta_time)
{
    player_t *player = world->player;
    camera_t *camera = world->camera;

    if (!camera->is_scrolling && player_reached_edge_of_screen(player, camera)) {
        world->player->can_move = sfFalse;
        start_camera_scroll(
            camera,
            player,
            calculate_new_camera_position(camera, player),
            ROOM_SCROLL_SPEED
        );
    }

    if (camera->is_scrolling) {
        continue_camera_scroll(camera, delta_time);
        
        if (camera_reached_new_room(camera)) {
            camera->is_scrolling = sfFalse;
            world->player->can_move = sfTrue;
        }
    }
}