#include "room_scroll.h"

void continue_camera_scroll(camera_t *camera, float delta_time)
{
    if (!camera->is_scrolling) {
        return;
    }

    camera->current_scroll += delta_time;

    float t = camera->current_scroll / camera->scroll_time;
    if (t > 1.0f) {
        t = 1.0f;
        camera->is_scrolling = sfFalse;
    }

    sfVector2f new_position;
    new_position.x = camera->start_position.x + t * (camera->target_position.x - camera->start_position.x);
    new_position.y = camera->start_position.y + t * (camera->target_position.y - camera->start_position.y);

    sfView_setCenter(camera->view, new_position);

    if (t == 1.0f) {
        camera->is_scrolling = sfFalse;
    }
}