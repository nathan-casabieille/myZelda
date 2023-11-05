#include "player.h"

void set_player_position(player_t *player, sfVector2f position)
{
    player->position = position;
    sfSprite_setPosition(player->object->sprite, player->position);
}