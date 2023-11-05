#ifndef __PLAYER_CONTROLLER_H
#define __PLAYER_CONTROLLER_H

#include "player.h"

typedef struct player_controller_s {
    player_t *player;
    float moveSpeed;
    sfBool keyLeft;
    sfBool keyRight;
    sfBool keyUp;
    sfBool keyDown;
} player_controller_t;

player_controller_t create_player_controller(player_t *player);
void handle_events(sfRenderWindow *window, player_controller_t *controller);
void update_player_controller(player_controller_t *controller);

#endif // __PLAYER_CONTROLLER_H
