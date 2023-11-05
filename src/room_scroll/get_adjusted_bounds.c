#include "room_scroll.h"

sfFloatRect get_adjusted_bounds(const camera_t *camera, float margin_x, float margin_y)
{
    sfFloatRect view_bounds = get_view_bounds(camera->view);
    view_bounds.left += margin_x;
    view_bounds.top += margin_y;
    view_bounds.width -= margin_x * 2;
    view_bounds.height -= margin_y * 2;

    return view_bounds;
}