#include "world.h"
#include "room_scroll.h"

void update_world(world_t *world, float delta_time)
{
    player_t *player = world->player;
    camera_t *camera = world->camera;

    update_camera_for_room_scroll(world, delta_time);
    ensure_player_within_camera_bounds(player, camera);
    animate_player(player, camera);
}