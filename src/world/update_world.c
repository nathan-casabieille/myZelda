#include "world.h"
#include "room_scroll.h"

void update_world(world_t *world, float delta_time)
{
    update_camera_for_room_scroll(world, delta_time);
    ensure_player_within_camera_bounds(world->player, world->camera);
}