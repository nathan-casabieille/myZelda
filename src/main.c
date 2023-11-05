#include "zelda.h"
#include "world.h"
#include "keyboard.h"

int main(int argc, char **argv)
{
    sfEvent event;

    world_t *world = create_world();

    sfVector2f movementOffset = {0, 0};


    sfBool movingInX = sfFalse;
    sfBool movingInY = sfFalse;

    if (!world)
        return EXIT_FAILURE;

    const float moveSpeed = 2.0f;
    sfBool keyLeft = sfFalse, keyRight = sfFalse, keyUp = sfFalse, keyDown = sfFalse;

    while (sfRenderWindow_isOpen(world->window)) {
        while (sfRenderWindow_pollEvent(world->window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(world->window);
            }
            if (event.type == sfEvtKeyPressed || event.type == sfEvtKeyReleased) {
                sfBool keyState = (event.type == sfEvtKeyPressed) ? sfTrue : sfFalse;

                switch (event.key.code) {
                    case sfKeyLeft:
                        keyLeft = keyState;
                        break;
                    case sfKeyRight:
                        keyRight = keyState;
                        break;
                    case sfKeyUp:
                        keyUp = keyState;
                        break;
                    case sfKeyDown:
                        keyDown = keyState;
                        break;
                }
            }
        }

        movingInX = keyLeft || keyRight;
        movingInY = keyUp || keyDown;
        movementOffset.x = 0;
        movementOffset.y = 0;

        if (movingInX && !movingInY) {
            movementOffset.x = keyLeft ? -moveSpeed : (keyRight ? moveSpeed : 0);
            world->player->moving = sfTrue;
            change_direction(world->player, keyLeft ? PLAYER_DIRECTION_LEFT : PLAYER_DIRECTION_RIGHT);
        }
        else if (movingInY && !movingInX) {
            movementOffset.y = keyUp ? -moveSpeed : (keyDown ? moveSpeed : 0);
            world->player->moving = sfTrue;
            change_direction(world->player, keyUp ? PLAYER_DIRECTION_UP : PLAYER_DIRECTION_DOWN);
        }

        // Now apply the movementOffset to move the player
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
