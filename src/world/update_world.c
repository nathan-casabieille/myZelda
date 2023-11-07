#include "world.h"
#include "room_scroll.h"
#include <stdio.h>
#include <math.h>

void update_world(world_t *world, float delta_time) {
    player_t *player = world->player;
    camera_t *camera = world->camera;

    update_camera_for_room_scroll(player, camera, delta_time);

    animate_player(player, camera);
}
