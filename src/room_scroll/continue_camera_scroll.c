#include "room_scroll.h"
#include <math.h>

void continue_camera_scroll(camera_t *camera, float delta_time)
{
    if (camera == NULL || !camera->is_scrolling) {
        return;
    }

    // Calcule la distance à parcourir en fonction de la vitesse de défilement et du temps delta
    float distance_to_scroll = ROOM_SCROLL_SPEED * delta_time;

    // Détermine la distance totale entre la position de départ et de fin
    sfVector2f total_distance;
    total_distance.x = camera->end_position.x - camera->start_position.x;
    total_distance.y = camera->end_position.y - camera->start_position.y;

    // Calcule la distance totale à parcourir
    float total_distance_length = (float)sqrt(total_distance.x * total_distance.x + total_distance.y * total_distance.y);

    // Calcule la progression du défilement (rapport entre ce qui a déjà été parcouru et la distance totale)
    camera->current_scroll += distance_to_scroll;
    float progress = camera->current_scroll / total_distance_length;
    
    // S'assure que la progression ne dépasse pas 1
    if (progress > 1.0f) {
        progress = 1.0f;
    }

    // Utilise la progression pour déterminer la nouvelle position de la caméra
    sfVector2f new_position;
    new_position.x = camera->start_position.x + total_distance.x * progress;
    new_position.y = camera->start_position.y + total_distance.y * progress;

    // Met à jour la vue de la caméra
    sfView_setCenter(camera->view, new_position);

    // Met à jour la position cible de la caméra sans arrêter le défilement
    camera->target_position = new_position;
}