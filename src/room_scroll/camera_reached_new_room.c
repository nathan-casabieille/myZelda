#include "room_scroll.h"

sfBool camera_reached_new_room(camera_t *camera)
{
    sfVector2f current_position = camera->target_position;
    sfVector2f end_position = camera->end_position;

    if (current_position.x == end_position.x
        && current_position.y == end_position.y) {
        return sfTrue;
    }
    return sfFalse;
}
