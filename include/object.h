#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "zelda.h"

#include <SFML/Graphics.h>

typedef struct object_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
} object_t;

object_t *create_object(char *path, sfVector2f pos, sfIntRect rect);
void destroy_object(object_t *object);
void draw_object(sfRenderWindow *window, object_t *object);

#endif // __OBJECT_H__