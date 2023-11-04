#include "world.h"
#include "player.h"

void draw_world(world_t *world)
{
    draw_object(world->window, world->map);
    animate_player(world->player);
    draw_object(world->window, world->player->object);
    sfRenderWindow_display(world->window);
}