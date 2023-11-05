#include "player_controller.h"

void handle_events(sfRenderWindow* window, player_controller_t *controller) {
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtKeyPressed || event.type == sfEvtKeyReleased) {
            sfBool keyState = (event.type == sfEvtKeyPressed) ? sfTrue : sfFalse;

            switch (event.key.code) {
                case sfKeyLeft:
                    controller->keyLeft = keyState;
                    break;
                case sfKeyRight:
                    controller->keyRight = keyState;
                    break;
                case sfKeyUp:
                    controller->keyUp = keyState;
                    break;
                case sfKeyDown:
                    controller->keyDown = keyState;
                    break;
            }
        }
    }
}