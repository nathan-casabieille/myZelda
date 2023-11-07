#include "helpers.h"

sfVector2f normalize_vector(sfVector2f vector)
{
    float length = vector_length(vector);
    if (length != 0) {
        vector.x /= length;
        vector.y /= length;
    }
    return vector;
}