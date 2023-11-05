#include "zelda.h"
#include "world.h"
#include "keyboard.h"
#include "player_controller.h"

int main(int argc, char **argv) {
    world_t *world = create_world();

    player_controller_t controller = create_player_controller(world->player);

    if (!world)
        return EXIT_FAILURE;

    while (sfRenderWindow_isOpen(world->window)) {
        handle_events(world->window, &controller);

        update_player_controller(&controller);

        // update_world(world);

        render_world(world);
    }

    destroy_world(world);

    return EXIT_SUCCESS;
}
