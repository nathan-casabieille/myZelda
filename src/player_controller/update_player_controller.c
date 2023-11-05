#include "player_controller.h"

void update_player_controller(player_controller_t *controller) {
    sfVector2f movementOffset = {0, 0};
    sfBool movingInX = controller->keyLeft || controller->keyRight;
    sfBool movingInY = controller->keyUp || controller->keyDown;

    if (movingInX && !movingInY) {
        movementOffset.x = controller->keyLeft ? -controller->moveSpeed : (controller->keyRight ? controller->moveSpeed : 0);
        controller->player->moving = sfTrue;
        change_direction(controller->player, controller->keyLeft ? PLAYER_DIRECTION_LEFT : PLAYER_DIRECTION_RIGHT);
    }
    else if (movingInY && !movingInX) {
        movementOffset.y = controller->keyUp ? -controller->moveSpeed : (controller->keyDown ? controller->moveSpeed : 0);
        controller->player->moving = sfTrue;
        change_direction(controller->player, controller->keyUp ? PLAYER_DIRECTION_UP : PLAYER_DIRECTION_DOWN);
    }

    if (controller->player->moving) {
        move_player(controller->player, movementOffset);
    }
}