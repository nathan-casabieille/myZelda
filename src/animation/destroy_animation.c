#include "animation.h"

void destroy_animation(animation_t *animation)
{
    free(animation);
}