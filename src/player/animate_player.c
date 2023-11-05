#include "player.h"
#include "camera.h"

void animate_player(player_t *player, camera_t *camera)
{
    sfIntRect animationRects[NBR_PLAYER_DIRECTIONS][PLAYER_ANIMATION_FRAME_COUNT] = {
        [PLAYER_DIRECTION_UP]    = { {69, 11, PLAYER_WIDTH, PLAYER_HEIGHT}, {86, 11, PLAYER_WIDTH, PLAYER_HEIGHT} },
        [PLAYER_DIRECTION_DOWN]  = { {1, 11, PLAYER_WIDTH, PLAYER_HEIGHT}, {18, 11, PLAYER_WIDTH, PLAYER_HEIGHT} },
        [PLAYER_DIRECTION_LEFT]  = { {103, 11, PLAYER_WIDTH, PLAYER_HEIGHT}, {120, 11, PLAYER_WIDTH, PLAYER_HEIGHT} },
        [PLAYER_DIRECTION_RIGHT] = { {35, 11, PLAYER_WIDTH, PLAYER_HEIGHT}, {52, 11, PLAYER_WIDTH, PLAYER_HEIGHT} }
    };
    
    if (player->moving || camera->is_scrolling) {
        sfTime elapsed = sfClock_getElapsedTime(player->animation_clock);
        if (sfTime_asMilliseconds(elapsed) >= sfTime_asMilliseconds(sfMilliseconds(PLAYER_ANIMATION_SPEED))) {
            player->current_frame = (player->current_frame + 1) % PLAYER_ANIMATION_FRAME_COUNT;
            sfClock_restart(player->animation_clock);
        }
    } else {
        player->current_frame = 0;
    }

    player->object->rect = animationRects[player->direction][player->current_frame];

    sfSprite_setTextureRect(player->object->sprite, player->object->rect);
}
