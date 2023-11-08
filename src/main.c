#include "zelda.h"
#include "world.h"
#include "keyboard.h"
#include "player_controller.h"

int main(int argc, char **argv) {
    world_t *world = create_world();

    player_controller_t controller = create_player_controller(world->player);

    sfTime elapsed;
    float delta_time;

    if (!world)
        return EXIT_FAILURE;

    while (sfRenderWindow_isOpen(world->window)) {
        elapsed = sfClock_restart(world->clock);
        delta_time = sfTime_asSeconds(elapsed);

        handle_events(world->window, &controller);

        update_player_controller(&controller, world->collisionImage);

        update_world(world, delta_time);

        render_world(world);
    }

    destroy_world(world);

    return EXIT_SUCCESS;
}
