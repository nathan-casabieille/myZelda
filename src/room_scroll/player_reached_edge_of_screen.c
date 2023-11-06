#include "room_scroll.h"

sfBool player_reached_edge_of_screen(const player_t *player, const camera_t *camera)
{
    sfFloatRect adjusted_bounds = get_view_bounds(camera->view);

    sfVector2f player_position = player->position;

    if (player_position.x <= adjusted_bounds.left || 
        player_position.x + PLAYER_WIDTH >= adjusted_bounds.left + adjusted_bounds.width ||
        player_position.y <= adjusted_bounds.top ||
        player_position.y + PLAYER_HEIGHT >= adjusted_bounds.top + adjusted_bounds.height) {
            return sfTrue;
    }

    return sfFalse;
}