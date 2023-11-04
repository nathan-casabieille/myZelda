#include "zelda.h"
#include "world.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    sfEvent event;

    world_t *world = create_world();

    if (!world)
        return EXIT_FAILURE;

    while (sfRenderWindow_isOpen(world->window)) {
        while (sfRenderWindow_pollEvent(world->window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(world->window);
            }
        }

        sfRenderWindow_clear(world->window, sfBlack);

        apply_camera(world->window, world->camera);

        draw_world(world);
    }

    destroy_world(world);

    return EXIT_SUCCESS;
}
