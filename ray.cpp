#include "ray.h"
#include "vec3.h"

/* ray::ray
 *
 * Constructs a ray object.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      None
 */
ray::ray()
{
}

/* ray::ray
 *
 * Constructs a ray object with the given origin and direction.
 *
 * Parameters:
 *      origin - The origin of the ray.
 *      direction - The direction of the ray.
 *
 * Return:
 *      None
 */
ray::ray(const point3 &origin, const vec3 &direction)
    : orig(origin), dir(direction)
{
}

/* ray::origin
 *
 * Returns the origin of the ray.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      The origin of the ray.
 */
const point3 &ray::origin() const
{
        return orig;
}

/* ray::direction
 *
 * Returns the direction of the ray.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      The direction of the ray.
 */
const vec3 &ray::direction() const
{
        return dir;
}

/* ray::at
 *
 * Returns the point at the given distance along the ray.
 *
 * Parameters:
 *      t - The distance along the ray.
 *
 * Return:
 *      The point at the given distance along the ray.
 */
point3 ray::at(double t) const
{
        return orig + t * dir;
}