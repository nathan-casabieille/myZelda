#include "room_scroll.h"

void start_camera_scroll(camera_t *camera, player_t *player, sfVector2f end_position, float time)
{
    camera->is_scrolling = sfTrue;
    camera->start_position = camera->target_position;
    camera->end_position = end_position;
    camera->scroll_time = time;
    camera->current_scroll = 0.0f;
}