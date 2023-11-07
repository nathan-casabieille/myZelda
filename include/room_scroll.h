#ifndef __ROOM_SCROLL_H_
#define __ROOM_SCROLL_H_

#include <SFML/Graphics.h>

#include "world.h"

sfVector2f calculate_new_camera_position(camera_t *camera, player_t *player);
sfBool camera_reached_new_room(camera_t *camera);
void continue_camera_scroll(camera_t *camera, float delta_time);
sfFloatRect get_view_bounds(const sfView *view);
void move_player_with_camera(player_t *player, camera_t *camera, float delta_time);
sfBool player_reached_edge_of_screen(player_t *player, camera_t *camera);
void position_player_after_scroll(player_t *player, camera_t *camera);
void start_camera_scroll(camera_t *camera, sfVector2f end_position, float time);
void update_camera_for_room_scroll(player_t *player, camera_t *camera, float delta_time);

#endif // __ROOM_SCROLL_H_