#include "room_scroll.h"

sfBool player_reached_edge_of_screen(player_t *player, camera_t *camera)
{
    sfFloatRect view_bounds = get_view_bounds(camera->view);
    sfVector2f player_position = player->object->pos;

    return player_position.x <= view_bounds.left + SCROLL_MARGIN ||
           player_position.x + PLAYER_WIDTH >= view_bounds.left + view_bounds.width - SCROLL_MARGIN ||
           player_position.y <= view_bounds.top + SCROLL_MARGIN ||
           player_position.y + PLAYER_HEIGHT >= view_bounds.top + view_bounds.height - SCROLL_MARGIN;
}