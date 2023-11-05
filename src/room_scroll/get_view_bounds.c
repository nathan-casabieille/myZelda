#include "room_scroll.h"

sfFloatRect get_view_bounds(const sfView *view)
{
    sfFloatRect view_bounds;
    sfVector2f center = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);

    // La vue est centrée autour du point de centre, donc on doit calculer
    // les coins supérieur gauche (x, y) du rectangle de la vue.
    view_bounds.left = center.x - size.x / 2;
    view_bounds.top = center.y - size.y / 2;
    view_bounds.width = size.x;
    view_bounds.height = size.y;

    return view_bounds;
}