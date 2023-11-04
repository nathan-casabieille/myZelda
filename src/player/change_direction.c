#include "player.h"
#include <stdio.h>

void change_direction(player_t *player, player_direction_t direction)
{
    if (player->direction != direction) {
        player->direction = direction;
    }
}