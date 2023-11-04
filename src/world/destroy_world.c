#include "world.h"

void destroy_world(world_t *world)
{
    sfRenderWindow_destroy(world->window);
    destroy_object(world->map);
    destroy_camera(world->camera);
    free(world);
}