#include "room_scroll.h"

sfBool camera_reached_new_room(camera_t *camera)
{
    sfVector2f current_position = sfView_getCenter(camera->view);

    const float epsilon = 0.01f;
    
    sfVector2f difference;
    difference.x = fabsf(camera->target_position.x - current_position.x);
    difference.y = fabsf(camera->target_position.y - current_position.y);

    if (difference.x <= epsilon && difference.y <= epsilon) {
        return sfTrue;
    }

    return sfFalse;
}