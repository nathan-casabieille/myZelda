#ifndef __CAMERA_H_
#define __CAMERA_H_

#include <SFML/Graphics.h>

typedef struct camera_s
{
    sfView* view;
    sfVector2f size;
    sfVector2f target_position;
    float zoom_level;
} camera_t;

void apply_camera(sfRenderWindow* window, camera_t* camera);
camera_t* create_camera(float zoom_level, sfVector2f target_position, sfVector2f size);
void update_camera(camera_t* camera, sfVector2f target_position);
void destroy_camera(camera_t* camera);

#endif // __CAMERA_H_