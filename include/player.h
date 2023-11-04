#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "object.h"

typedef struct player_s {
    object_t *object;
    sfVector2f position;
} player_t;

player_t *create_player(sfVector2f position);
void destroy_player(player_t *player);

#endif // __PLAYER_H_