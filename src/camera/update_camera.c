#include "camera.h"

void update_camera(camera_t* camera, sfVector2f target_position)
{
    camera->target_position = target_position;
    sfView_setCenter(camera->view, camera->target_position);
}