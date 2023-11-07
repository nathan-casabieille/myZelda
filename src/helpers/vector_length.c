#include "helpers.h"

float vector_length(sfVector2f vector)
{
    return (float)sqrt(vector.x * vector.x + vector.y * vector.y);
}