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

object_t *create_object(const char *path, sfVector2f pos, sfIntRect rect);
void destroy_object(object_t *object);
void render_object(sfRenderWindow *window, object_t *object);
void animate_object(object_t *object, int frame_count, int animation_speed, int offset_x, sfClock *clock);
void place_object(object_t *object, sfVector2f new_position);
void move_object(object_t *object, sfVector2f offset);

#endif // __OBJECT_H__