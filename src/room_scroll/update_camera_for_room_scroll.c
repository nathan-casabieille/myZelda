#include "room_scroll.h"
#include <stdio.h>

void update_camera_for_room_scroll(world_t *world, float delta_time)
{
    player_t *player = world->player;
    camera_t *camera = world->camera;

    if (player_reached_edge_of_screen(player, camera)) {
        world->player->can_move = sfFalse;
        
        sfVector2f new_camera_pos = calculate_new_camera_position(camera, player);

        start_camera_scroll(camera, player, new_camera_pos, 1.0);
    }

    if (camera->is_scrolling) {
        continue_camera_scroll(camera, delta_time);
        
        if (camera_reached_new_room(camera)) {
            world->player->can_move = sfTrue;
        }
    }
}