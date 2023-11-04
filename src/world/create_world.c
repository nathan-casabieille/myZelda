#include "world.h"

void init_window(world_t *world)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    world->window = sfRenderWindow_create(mode, WINDOW_NAME, sfResize | sfClose, NULL);
}

sfVector2f calculate_spawn_tile_pos(void)
{
    sfVector2f tile_center = {
        (SPAWN_TILE_X * (TILE_WIDTH + 1)) + ((TILE_WIDTH + 1) / 2),
        (SPAWN_TILE_Y * (TILE_HEIGHT + 1)) + ((TILE_HEIGHT + 1) / 2)
    };
    return tile_center;
}

world_t* create_world(void)
{
    world_t *world = malloc(sizeof(world_t));

    init_window(world);
    world->map = create_object(
        MAP_FILE_PATH,
        (sfVector2f){0, 0},
        (sfIntRect){1, 1, MAP_WIDTH, MAP_HEIGHT}
    );
    world->camera = create_camera(
        1.0,
        calculate_spawn_tile_pos(),
        (sfVector2f){TILE_WIDTH, TILE_HEIGHT}
    );
    return world;
}