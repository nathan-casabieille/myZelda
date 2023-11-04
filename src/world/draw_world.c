#include "world.h"

void draw_world(world_t *world)
{
    draw_object(world->window, world->map);
    animate_object(world->player->object, 2, 150, 1, world->clock);
    draw_object(world->window, world->player->object);
    sfRenderWindow_display(world->window);
}