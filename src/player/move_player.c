#include "player.h"

void move_player(player_t *player, sfVector2f offset)
{
    player->position.x += offset.x;
    player->position.y += offset.y;
    sfSprite_setPosition(player->object->sprite, player->position);
}