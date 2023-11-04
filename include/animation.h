#ifndef __ANIMATION_H_
#define __ANIMATION_H_

#include <stdlib.h>
#include <SFML/Graphics.h>

#define ANIMATION_OFFSET_X 1

typedef struct animation_s
{
    sfIntRect rect;
    int frame_count;
    int speed;
    int offset_x;
} animation_t;

void destroy_animation(animation_t *animation);
animation_t *create_animation(sfIntRect rect, int frame_count, int speed, int offset_x);

#endif // __ANIMATION_H_