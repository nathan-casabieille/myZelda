#include "player_controller.h"
#include "collision.h"

void update_player_controller(player_controller_t *controller, sfImage *collisionImage)
{
    sfVector2f movementOffset = {0, 0};

    sfBool movingInX = controller->keyLeft || controller->keyRight;
    sfBool movingInY = controller->keyUp || controller->keyDown;

    player_t *player = controller->player;

    player->moving = sfFalse;

    if (player->can_move == sfFalse) {
        return;
    }

    if (movingInX && !movingInY) {
        movementOffset.x = controller->keyLeft ? -controller->moveSpeed : controller->moveSpeed;
        player->moving = sfTrue;
        change_direction(player, controller->keyLeft ? PLAYER_DIRECTION_LEFT : PLAYER_DIRECTION_RIGHT);
    }
    else if (movingInY && !movingInX) {
        movementOffset.y = controller->keyUp ? -controller->moveSpeed : controller->moveSpeed;
        player->moving = sfTrue;
        change_direction(player, controller->keyUp ? PLAYER_DIRECTION_UP : PLAYER_DIRECTION_DOWN);
    }

    if (player->moving && player->can_move) {
        move_object_if_possible(player, movementOffset, collisionImage);
    }
}