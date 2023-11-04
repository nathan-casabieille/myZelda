#include "camera.h"
#include "zelda.h"

camera_t* create_camera(float zoom_level, sfVector2f target_position, sfVector2f size)
{
    camera_t* camera = malloc(sizeof(camera_t));
    if (!camera) {
        exit(EXIT_FAILURE);
    }

    camera->view = sfView_create();
    camera->zoom_level = zoom_level;
    camera->target_position = target_position;
    camera->size = size;

    sfView_setSize(camera->view, size);
    sfView_setCenter(camera->view, target_position);

    return camera;
}