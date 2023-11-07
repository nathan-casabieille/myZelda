#include "room_scroll.h"
#include "helpers.h"

void move_player_with_camera(player_t *player, camera_t *camera, float delta_time)
{
    if (camera->is_scrolling) {
        sfVector2f direction = normalize_vector((sfVector2f){
            camera->end_position.x - camera->start_position.x,
            camera->end_position.y - camera->start_position.y
        });

        sfVector2f player_movement = {
            direction.x * ROOM_SCROLL_SPEED * delta_time,
            direction.y * ROOM_SCROLL_SPEED * delta_time
        };

        move_object(player->object, player_movement);
    }
}