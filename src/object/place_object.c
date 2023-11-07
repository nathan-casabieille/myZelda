#include "object.h"

void place_object(object_t *object, sfVector2f new_position)
{
    object->pos = new_position;
    sfSprite_setPosition(object->sprite, new_position);
}