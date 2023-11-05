#include "room_scroll.h"

sfBool player_reached_edge_of_screen(const player_t *player, const camera_t *camera)
{
    // Obtenez la limite de la vue actuelle de la caméra
    sfFloatRect view_bounds = get_view_bounds(camera->view);

    // Convertir la taille de la vue en unités du monde
    sfVector2f view_size_world = camera->size; // On suppose que la taille de la vue est déjà ajustée au niveau du monde

    // Obtenir les limites de la position du joueur dans le monde
    sfVector2f player_position = player->position;

    // Calculer les marges (seuil) pour déclencher le scrolling. Ce seuil pourrait être une petite valeur
    // ou égal à la largeur / hauteur du sprite du joueur pour un scrolling immédiat lorsque le joueur atteint le bord.
    float margin_x = PLAYER_WIDTH;
    float margin_y = PLAYER_HEIGHT;

    // Vérifier si le joueur a atteint les bords de la vue de la caméra
    if (player_position.x <= (view_bounds.left + margin_x)) {
        return sfTrue; // Bord gauche atteint
    }
    if (player_position.x >= (view_bounds.left + view_size_world.x - margin_x)) {
        return sfTrue; // Bord droit atteint
    }
    if (player_position.y <= ((view_bounds.top + margin_y) - PLAYER_HEIGHT)) {
        return sfTrue; // Bord supérieur atteint
    }
    if (player_position.y >= (view_bounds.top + view_size_world.y - margin_y)) {
        return sfTrue; // Bord inférieur atteint
    }

    // Le joueur n'a pas atteint le bord
    return sfFalse;
}