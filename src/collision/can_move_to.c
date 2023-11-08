#include "collision.h"

sfBool can_move_to(player_t *player, sfVector2f position, sfImage* collisionImage)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(player->object->sprite);

    sfVector2f bottomCenterPosition = {
        position.x + bounds.width / 2,
        position.y + bounds.height
    };

    for (int y = 0; y < (PLAYER_HEIGHT / 2); ++y) {
        for (int x = -(PLAYER_WIDTH / 4); x < (PLAYER_WIDTH / 4); ++x) {
            sfColor pixelColor = sfImage_getPixel(collisionImage,
                (unsigned int)(bottomCenterPosition.x + x), 
                (unsigned int)(bottomCenterPosition.y - y));

            if (pixelColor.r == 0 && pixelColor.g == 0 && pixelColor.b == 0) {
                return sfFalse;
            }
        }
    }

    return sfTrue;
}