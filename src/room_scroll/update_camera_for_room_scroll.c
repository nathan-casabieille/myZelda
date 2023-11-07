#include "room_scroll.h"

void update_camera_for_room_scroll(player_t *player, camera_t *camera, float delta_time)
{
    if (camera->is_scrolling) {
        continue_camera_scroll(camera, delta_time);
        
        if (camera_reached_new_room(camera)) {
            camera->is_scrolling = sfFalse;
            position_player_after_scroll(player, camera);
            player->can_move = sfTrue;
        } else {
            if (player_reached_edge_of_screen(player, camera)) {
                move_player_with_camera(player, camera, delta_time);
            }
        }
    } else {
        if (player_reached_edge_of_screen(player, camera)) {
            player->can_move = sfFalse;
            start_camera_scroll(camera, calculate_new_camera_position(camera, player), ROOM_SCROLL_SPEED);
        }
    }
}