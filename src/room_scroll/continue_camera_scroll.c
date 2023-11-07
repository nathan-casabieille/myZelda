#include "room_scroll.h"
#include "helpers.h"

void continue_camera_scroll(camera_t *camera, float delta_time)
{
    if (!camera || !camera->is_scrolling) {
        return;
    }

    float distance_to_scroll = ROOM_SCROLL_SPEED * delta_time;
    sfVector2f total_distance = {
        camera->end_position.x - camera->start_position.x,
        camera->end_position.y - camera->start_position.y
    };

    camera->current_scroll += distance_to_scroll;
    float progress = fminf(camera->current_scroll / vector_length(total_distance), 1.0f);

    sfVector2f new_position = {
        camera->start_position.x + total_distance.x * progress,
        camera->start_position.y + total_distance.y * progress
    };

    sfView_setCenter(camera->view, new_position);
    camera->target_position = new_position;
}