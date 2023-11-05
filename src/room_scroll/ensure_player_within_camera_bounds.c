#include "room_scroll.h"
#include <stdio.h>

void ensure_player_within_camera_bounds(player_t *player, camera_t *camera) {

    if (!camera->is_scrolling) {
        return;
    }
    // Obtenez la limite de la vue actuelle de la caméra
    sfFloatRect view_bounds = get_view_bounds(camera->view);

    // Convertir la taille de la vue en unités du monde
    sfVector2f view_size_world = camera->size; // On suppose que la taille de la vue est déjà ajustée au niveau du monde

    // Obtenir les limites de la position du joueur dans le monde
    sfVector2f player_position = player->position;

    // Définir les marges (seuil)
    float margin_x = PLAYER_WIDTH + 15;
    float margin_y = PLAYER_HEIGHT + 15;

    // Corriger la position du joueur si nécessaire
    // Empêcher le joueur de dépasser le bord gauche de la caméra
    if (player_position.x < view_bounds.left + margin_x) {
        player_position.x = view_bounds.left + margin_x;
    }

    // Empêcher le joueur de dépasser le bord droit de la caméra
    if (player_position.x > view_bounds.left + view_size_world.x - margin_x) {
        player_position.x = view_bounds.left + view_size_world.x - margin_x;
    }

    // Empêcher le joueur de dépasser le bord supérieur de la caméra
    if (player_position.y < view_bounds.top + margin_y) {
        player_position.y = view_bounds.top + margin_y;
    }

    // Empêcher le joueur de dépasser le bord inférieur de la caméra
    if (player_position.y > view_bounds.top + view_size_world.y - margin_y) {
        player_position.y = view_bounds.top + view_size_world.y - margin_y;
    }

    set_player_position(player, player_position);
}
