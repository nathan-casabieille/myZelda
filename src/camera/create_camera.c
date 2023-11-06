#include "camera.h"
#include "zelda.h"

camera_t *create_camera(float zoom_level, sfVector2f target_position, sfVector2f size)
{
    camera_t *camera = malloc(sizeof(camera_t));
    if (!camera) {
        exit(EXIT_FAILURE);
    }

    camera->view = sfView_create();
    camera->zoom_level = zoom_level;
    camera->target_position = target_position;
    camera->size = size;

    sfView_setSize(camera->view, size);
    update_camera(camera, target_position);

    camera->is_scrolling = sfFalse;
    camera->start_position = target_position;
    camera->end_position = target_position;
    camera->scroll_time = 0.0f;
    camera->current_scroll = 0.0f;

    return camera;
}