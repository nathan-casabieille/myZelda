#include "object.h"

void draw_object(sfRenderWindow *window, object_t *object)
{
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}