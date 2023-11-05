#include "player.h"

void move_player(player_t *player, sfVector2f offset)
{
    if (player->can_move == sfTrue) {
        player->position.x += offset.x;
        player->position.y += offset.y;
        sfSprite_move(player->object->sprite, offset);
    }
}