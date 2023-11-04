#ifndef __PLAYER_H_
#define __PLAYER_H_

#include "object.h"
#include "animation.h"

#define NBR_PLAYER_DIRECTIONS 4
#define PLAYER_ANIMATION_SPEED 150
#define PLAYER_ANIMATION_FRAME_COUNT 2

typedef enum player_direction_s
{
    PLAYER_DIRECTION_UP,
    PLAYER_DIRECTION_DOWN,
    PLAYER_DIRECTION_LEFT,
    PLAYER_DIRECTION_RIGHT
} player_direction_t;

typedef struct player_s
{
    object_t *object;
    sfVector2f position;
    player_direction_t direction;
    sfClock* animation_clock;
    int current_frame;
    sfBool moving;
} player_t;

player_t *create_player(sfVector2f position);
void destroy_player(player_t *player);
void move_player(player_t *player, sfVector2f offset);

void animate_player(player_t *player);

void change_direction(player_t *player, player_direction_t direction);

#endif // __PLAYER_H_