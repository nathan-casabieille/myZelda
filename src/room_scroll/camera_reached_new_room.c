#include "room_scroll.h"

sfBool camera_reached_new_room(camera_t *camera)
{
    return camera->target_position.x == camera->end_position.x &&
           camera->target_position.y == camera->end_position.y;
}