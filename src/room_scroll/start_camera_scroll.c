#include "room_scroll.h"

void start_camera_scroll(camera_t *camera, player_t *player, sfVector2f new_target_position, float time)
{
    if (camera->is_scrolling) {
        return;
    }

    camera->is_scrolling = sfTrue;
    camera->start_position = sfView_getCenter(camera->view);
    camera->target_position = new_target_position;
    camera->scroll_time = time;
    camera->current_scroll = 0.0f;
}