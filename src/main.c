#include "zelda.h"
#include "object.h"
#include "camera.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow* window;

    object_t *object;
    sfEvent event;

    camera_t *camera;

    sfVector2f camera_position = {0, 0};

    window = sfRenderWindow_create(mode, WINDOW_NAME, sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;

    object = create_object(
        "assets/map.png",
        (sfVector2f){0, 0},
        (sfIntRect){1, 1, MAP_WIDTH, MAP_HEIGHT}
    );

    sfVector2f tile_center = {
        (SPAWN_TILE_X * (TILE_WIDTH + 1)) + ((TILE_WIDTH + 1) / 2),
        (SPAWN_TILE_Y * (TILE_HEIGHT + 1)) + ((TILE_HEIGHT + 1) / 2)
    };

    printf("tile_center: (%f, %f)\n", tile_center.x, tile_center.y);

    camera = create_camera(
        1.0,
        tile_center,
        (sfVector2f){TILE_WIDTH, TILE_HEIGHT}
    );

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlack);

        // update_camera(camera, (sfVector2f){camera_position.x, camera_position.y});

        apply_camera(window, camera);

        draw_object(window, object);

        sfRenderWindow_display(window);
        
        // camera_position.x += 20;
        // camera_position.y += 20;

        // sfSleep((sfTime){100000});
    }

    sfRenderWindow_destroy(window);
    destroy_camera(camera);
    destroy_object(object);

    return EXIT_SUCCESS;
}
