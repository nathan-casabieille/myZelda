#include "player_controller.h"

player_controller_t create_player_controller(player_t *player) {
    player_controller_t controller = {
        .player = player,
        .moveSpeed = PLAYER_WALKING_SPEED,
        .keyLeft = sfFalse,
        .keyRight = sfFalse,
        .keyUp = sfFalse,
        .keyDown = sfFalse
    };
    return controller;
}