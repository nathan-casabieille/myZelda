#include "object.h"

void animate_object(object_t *object, int frame_count, int animation_speed, int offset_x, sfClock *clock)
{
    if (!object || !clock)
        return;

    sfTime time = sfClock_getElapsedTime(clock);

    int frame_index = (sfTime_asMilliseconds(time) / animation_speed) % frame_count;

    object->rect.left = frame_index * (object->rect.width + offset_x) + offset_x;

    sfSprite_setTextureRect(object->sprite, object->rect);
}