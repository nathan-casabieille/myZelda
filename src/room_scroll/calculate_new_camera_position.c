#include "room_scroll.h"

sfVector2f calculate_new_camera_position(camera_t *camera, player_t *player)
{
    sfVector2f adjustment = {0, 0};
    float width = camera->size.x;
    float height = camera->size.y;

    switch (player->direction) {
        case PLAYER_DIRECTION_UP:    adjustment.y = -height; break;
        case PLAYER_DIRECTION_DOWN:  adjustment.y = height;  break;
        case PLAYER_DIRECTION_LEFT:  adjustment.x = -width;  break;
        case PLAYER_DIRECTION_RIGHT: adjustment.x = width;   break;
    }

    return (sfVector2f){camera->target_position.x + adjustment.x, 
                        camera->target_position.y + adjustment.y};
}
