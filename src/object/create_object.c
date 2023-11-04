#include "object.h"

object_t *create_object(char *path, sfVector2f pos, sfIntRect rect)
{
    object_t *object = malloc(sizeof(object_t));

    object->texture = sfTexture_createFromFile(path, NULL);
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setPosition(object->sprite, pos);
    sfSprite_setTextureRect(object->sprite, rect);
    return (object);
}