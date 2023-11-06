#ifndef __ROOM_SCROLL_H_
#define __ROOM_SCROLL_H_

#include <SFML/Graphics.h>

#include "world.h"

sfVector2f calculate_new_camera_position(camera_t *camera, player_t *player);
sfBool camera_reached_new_room(camera_t *camera);
void continue_camera_scroll(camera_t *camera, float delta_time);
void ensure_player_within_camera_bounds(player_t *player, camera_t *camera);
sfFloatRect get_view_bounds(const sfView *view);
sfBool player_reached_edge_of_screen(const player_t *player, const camera_t *camera);
void start_camera_scroll(camera_t *camera, player_t *player, sfVector2f new_target_position, float time);
void update_camera_for_room_scroll(world_t *world, float delta_time);
sfFloatRect get_adjusted_bounds(const camera_t *camera, float margin_x, float margin_y);

#endif // __ROOM_SCROLL_H_