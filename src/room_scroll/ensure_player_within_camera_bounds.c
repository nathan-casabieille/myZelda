#include "room_scroll.h"

void ensure_player_within_camera_bounds(player_t *player, camera_t *camera) {
    sfVector2f player_position;
    sfFloatRect adjusted_bounds;

    if (!camera->is_scrolling) {
        return;
    }

    // TODO: fix margins

    adjusted_bounds = get_view_bounds(camera->view);
    player_position = player->position;

    // left side reached
    if (player_position.x < adjusted_bounds.left) {
        player_position.x = adjusted_bounds.left + (PLAYER_WIDTH + 1);
    }

    // right side reached
    else if (player_position.x + PLAYER_WIDTH > adjusted_bounds.left + adjusted_bounds.width) {
        player_position.x = adjusted_bounds.left + adjusted_bounds.width - (PLAYER_WIDTH * 2);
    }

    // top side reached
    if (player_position.y < adjusted_bounds.top) {
        player_position.y = adjusted_bounds.top + PLAYER_HEIGHT;
    }

    // bottom side reached
    else if (player_position.y + PLAYER_HEIGHT > adjusted_bounds.top + adjusted_bounds.height) {
        player_position.y = adjusted_bounds.top + adjusted_bounds.height - (PLAYER_HEIGHT * 2);
    }

    set_player_position(player, player_position);
}