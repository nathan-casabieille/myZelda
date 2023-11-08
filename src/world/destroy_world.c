#include "world.h"

void destroy_world(world_t *world)
{
    sfRenderWindow_destroy(world->window);
    destroy_object(world->map);
    destroy_camera(world->camera);
    destroy_player(world->player);
    sfImage_destroy(world->collisionImage);
    free(world);
}