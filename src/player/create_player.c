#include "player.h"
#include "zelda.h"

player_t *create_player(sfVector2f position)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;

    player->moving = sfFalse;
    player->can_move = sfTrue;
    player->direction = PLAYER_DIRECTION_DOWN;

    player->object = create_object(
        PLAYER_SPRITE_PATH,
        position,
        (sfIntRect){1, 11, PLAYER_WIDTH, PLAYER_HEIGHT}
    );

    if (!player->object)
        return NULL;

    player->animation_clock = sfClock_create();

    return player;   
}