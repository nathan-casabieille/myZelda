#ifndef __WORLD_H_
#define __WORLD_H_

#include <SFML/Graphics.h>

#include "object.h"
#include "camera.h"
#include "player.h"

typedef struct world_s
{
    sfRenderWindow* window;
    object_t *map;
    camera_t *camera;
    player_t *player;
} world_t;

world_t *create_world(void);
void render_world(world_t *world);
void destroy_world(world_t *world);

#endif //__WORLD_H_