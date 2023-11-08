#include "collision.h"

void move_object_if_possible(player_t *player, sfVector2f movementOffset, sfImage* collisionImage)
{
    sfVector2f newPosition = {
        sfSprite_getPosition(player->object->sprite).x + movementOffset.x,
        sfSprite_getPosition(player->object->sprite).y + movementOffset.y
    };

    if (can_move_to(player, newPosition, collisionImage)) {
        move_object(player->object, movementOffset);
    }
}