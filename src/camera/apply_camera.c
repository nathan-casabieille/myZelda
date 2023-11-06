#include "camera.h"

void apply_camera(sfRenderWindow *window, camera_t *camera)
{
    sfRenderWindow_setView(window, camera->view);
}