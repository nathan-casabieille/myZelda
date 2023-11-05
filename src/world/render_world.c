#include "world.h"
#include "player.h"

void render_world(world_t *world)
{
    sfRenderWindow_clear(world->window, sfBlack);

    apply_camera(world->window, world->camera);
    render_object(world->window, world->map);

    render_object(world->window, world->player->object);

    sfRenderWindow_display(world->window);
}