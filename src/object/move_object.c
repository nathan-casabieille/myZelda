#include "object.h"

void move_object(object_t *object, sfVector2f offset)
{
    object->pos.x += offset.x;
    object->pos.y += offset.y;
    sfSprite_move(object->sprite, offset);
}