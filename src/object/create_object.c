#include "object.h"

object_t *create_object(const char *path, sfVector2f pos, sfIntRect rect)
{
    if (!path) {
        return NULL;
    }

    object_t *object = malloc(sizeof(object_t));
    if (!object) {
        return NULL;
    }

    object->texture = sfTexture_createFromFile(path, NULL);
    if (!object->texture) {
        free(object);
        return NULL;
    }

    object->sprite = sfSprite_create();
    if (!object->sprite) {
        sfTexture_destroy(object->texture);
        free(object);
        return NULL;
    }

    object->rect = rect;

    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setPosition(object->sprite, pos);
    sfSprite_setTextureRect(object->sprite, rect);

    return object;
}
