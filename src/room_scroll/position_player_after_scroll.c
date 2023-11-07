#include "room_scroll.h"

void position_player_after_scroll(player_t *player, camera_t *camera)
{
    sfFloatRect view_bounds = get_view_bounds(camera->view);
    sfVector2f new_player_position = player->object->pos;
    
    switch (player->direction) {
        case PLAYER_DIRECTION_RIGHT:
            new_player_position.x = view_bounds.left + PLAYER_BORDER_OFFSET;
            break;
        case PLAYER_DIRECTION_LEFT:
            new_player_position.x = view_bounds.left + ROOM_WIDTH - player->object->rect.width - PLAYER_BORDER_OFFSET;
            break;
        case PLAYER_DIRECTION_DOWN:
            new_player_position.y = view_bounds.top + PLAYER_BORDER_OFFSET;
            break;
        case PLAYER_DIRECTION_UP:
            new_player_position.y = view_bounds.top + ROOM_HEIGHT - player->object->rect.height - PLAYER_BORDER_OFFSET;
            break;
    }

    place_object(player->object, new_player_position);
}