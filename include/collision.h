#ifndef __COLLISION_H_
#define __COLLISION_H_

#include "world.h"
#include "player_controller.h"

sfBool can_move_to(player_t *player, sfVector2f position, sfImage* collisionImage);
void move_object_if_possible(player_t *player, sfVector2f movementOffset, sfImage* collisionImage);

#endif // __COLLISION_H_