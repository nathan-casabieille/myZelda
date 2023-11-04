#include "animation.h"

animation_t *create_animation(sfIntRect rect, int frame_count, int speed, int offset_x)
{
    animation_t *animation = malloc(sizeof(animation_t));

    if (!animation) {
        return NULL;
    }

    animation->rect = rect;
    animation->frame_count = frame_count;
    animation->speed = speed;
    animation->offset_x = offset_x;

    return animation;
}