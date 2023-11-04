#include "zelda.h"
#include "world.h"
#include "keyboard.h"

int main(int argc, char **argv)
{
    sfEvent event;

    world_t *world = create_world();

    sfVector2f movementOffset = {0, 0};

    if (!world)
        return EXIT_FAILURE;

    while (sfRenderWindow_isOpen(world->window)) {
                while (sfRenderWindow_pollEvent(world->window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(world->window);
            } else if (event.type == sfEvtKeyPressed) {
                switch (event.key.code) {
                    case sfKeyLeft:
                        movementOffset.x = -2;
                        world->player->moving = sfTrue;
                        change_direction(world->player, PLAYER_DIRECTION_LEFT);
                        break;
                    case sfKeyRight:
                        movementOffset.x = 2;
                        world->player->moving = sfTrue;
                        change_direction(world->player, PLAYER_DIRECTION_RIGHT);
                        break;
                    case sfKeyUp:
                        movementOffset.y = -2;
                        world->player->moving = sfTrue;
                        change_direction(world->player, PLAYER_DIRECTION_UP);
                        break;
                    case sfKeyDown:
                        movementOffset.y = 2;
                        world->player->moving = sfTrue;
                        change_direction(world->player, PLAYER_DIRECTION_DOWN);
                        break;
                    default:
                        break;
                }
            } else if (event.type == sfEvtKeyReleased) {
                switch (event.key.code) {
                    case sfKeyLeft:
                    case sfKeyRight:
                        movementOffset.x = 0;
                        break;
                    case sfKeyUp:
                    case sfKeyDown:
                        movementOffset.y = 0;
                        break;
                    default:
                        break;
                }

                if (movementOffset.x == 0 && movementOffset.y == 0) {
                    world->player->moving = sfFalse;
                }
            }
        }

        if (world->player->moving) {
            move_player(world->player, movementOffset);
        }

        sfRenderWindow_clear(world->window, sfBlack);

        apply_camera(world->window, world->camera);

        draw_world(world);
    }

    destroy_world(world);

    return EXIT_SUCCESS;
}
