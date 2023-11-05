#include "room_scroll.h"

sfVector2f calculate_new_camera_position(camera_t *camera, player_t *player)
{
    sfVector2f new_camera_pos = camera->target_position;

    switch (player->direction) {
        case PLAYER_DIRECTION_UP:
            new_camera_pos.y -= camera->size.y;
            break;
        case PLAYER_DIRECTION_DOWN:
            new_camera_pos.y += camera->size.y;
            break;
        case PLAYER_DIRECTION_LEFT:
            new_camera_pos.x -= camera->size.x;
            break;
        case PLAYER_DIRECTION_RIGHT:
            new_camera_pos.x += camera->size.x;
            break;
    }

    return new_camera_pos;
}