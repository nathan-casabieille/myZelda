#include "player.h"

void destroy_player(player_t *player)
{
    destroy_object(player->object);
    free(player);
}