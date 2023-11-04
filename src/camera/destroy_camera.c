#include "camera.h"
#include <stdlib.h>

void destroy_camera(camera_t* camera)
{
    if (camera) {
        sfView_destroy(camera->view);
        free(camera);
    }
}