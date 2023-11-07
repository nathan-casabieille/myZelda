#include "room_scroll.h"

sfFloatRect get_view_bounds(const sfView *view)
{
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);
    return (sfFloatRect){center.x - size.x / 2, center.y - size.y / 2, size.x, size.y};
}