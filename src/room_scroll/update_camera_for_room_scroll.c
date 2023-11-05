#include "room_scroll.h"

void update_camera_for_room_scroll(world_t *world, float delta_time)
{
    player_t *player = world->player;
    camera_t *camera = world->camera;

    if (player_reached_edge_of_screen(player, camera)) {
        // Calculez la nouvelle position de la caméra pour la nouvelle salle
        sfVector2f new_camera_pos = calculate_new_camera_position(camera, player);

        // Commencez à interpoler la position de la caméra vers la nouvelle salle
        start_camera_scroll(camera, player, new_camera_pos, 1.0);

        // Empêchez le joueur de se déplacer pendant le scrolling
        world->player->can_move = sfFalse;
    }

    // Si la caméra est en train de défiler, mettez à jour sa position
    if (camera->is_scrolling) {
        continue_camera_scroll(camera, delta_time);
        
        // Vérifiez si le scrolling est terminé
        if (camera_reached_new_room(camera)) {
            // Scrolling terminé, permettez au joueur de bouger à nouveau
            world->player->can_move = sfTrue;
        }
    }
}