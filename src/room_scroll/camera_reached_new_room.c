#include "room_scroll.h"

sfBool camera_reached_new_room(camera_t *camera)
{
    // On obtient la position actuelle de la caméra
    sfVector2f current_position = sfView_getCenter(camera->view);

    // On compare la position actuelle de la caméra avec la position cible.
    // En supposant que vous voulez une certaine tolérance sur la position en raison
    // de possibles imprécisions en virgule flottante, vous pouvez utiliser une petite valeur 'epsilon'.
    const float epsilon = 0.01f; // Vous pouvez ajuster cette valeur à vos besoins.
    
    // Calculez la différence entre la position actuelle et la cible
    sfVector2f difference;
    difference.x = fabsf(camera->target_position.x - current_position.x);
    difference.y = fabsf(camera->target_position.y - current_position.y);

    // Vérifiez si la caméra est proche de la position cible à l'intérieur de la tolérance 'epsilon'
    if (difference.x <= epsilon && difference.y <= epsilon) {
        // La caméra a atteint la nouvelle "pièce" ou section.
        return sfTrue;
    }

    // La caméra n'a pas encore atteint la nouvelle section.
    return sfFalse;
}