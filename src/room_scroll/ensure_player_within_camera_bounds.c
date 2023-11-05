#include "room_scroll.h"
#include <stdio.h>

void ensure_player_within_camera_bounds(player_t *player, camera_t *camera) {

    if (!camera->is_scrolling) {
        return;
    }

    sfFloatRect adjusted_bounds = get_adjusted_bounds(camera, 1.0f, 1.0f);

    sfVector2f player_position = player->position;

    if (player_position.x < adjusted_bounds.left) {
        player_position.x = adjusted_bounds.left;
    }
    else if (player_position.x + PLAYER_WIDTH > adjusted_bounds.left + adjusted_bounds.width) {
        player_position.x = adjusted_bounds.left + adjusted_bounds.width - PLAYER_WIDTH;
    }

    if (player_position.y < adjusted_bounds.top) {
        player_position.y = adjusted_bounds.top;
    }
    else if (player_position.y + PLAYER_HEIGHT > adjusted_bounds.top + adjusted_bounds.height) {
        player_position.y = adjusted_bounds.top + adjusted_bounds.height - PLAYER_HEIGHT;
    }

    set_player_position(player, player_position);
}
