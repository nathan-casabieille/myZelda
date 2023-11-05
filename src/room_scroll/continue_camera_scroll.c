#include "room_scroll.h"

// Fonction pour continuer le défilement de la caméra à chaque frame
void continue_camera_scroll(camera_t *camera, float delta_time)
{
    if (!camera->is_scrolling) {
        return;
    }

    // Augmenter le temps écoulé
    camera->current_scroll += delta_time;

    // Calculer la progression
    float t = camera->current_scroll / camera->scroll_time;
    if (t > 1.0f) {
        t = 1.0f;
        camera->is_scrolling = sfFalse;
    }

    // Calculer la nouvelle position en interpolant entre le début et la fin
    sfVector2f new_position;
    new_position.x = camera->start_position.x + t * (camera->target_position.x - camera->start_position.x);
    new_position.y = camera->start_position.y + t * (camera->target_position.y - camera->start_position.y);

    // Appliquer la nouvelle position à la vue de la caméra
    sfView_setCenter(camera->view, new_position);

    // Si t == 1.0f, alors le défilement est terminé
    if (t == 1.0f) {
        camera->is_scrolling = sfFalse;
    }
}