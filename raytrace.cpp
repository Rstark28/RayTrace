#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>
#include <cmath>

/* hit_sphere
 *
 * Determines if the given ray intersects the sphere.
 *
 * Parameters:
 *      center - The center of the sphere.
 *      radius - The radius of the sphere.
 *      r - The ray to check for intersection.
 *
 * Return:
 *      True if the ray intersects the sphere, false otherwise.
 */
double hit_sphere(const point3 &center, double radius, const ray &r)
{
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius * radius;
        auto discriminant = h * h - a * c;

        if (discriminant < 0)
        {
                return -1.0;
        }
        else
        {
                return (h - std::sqrt(discriminant)) / a;
        }
}

/* ray_color
 *
 * Returns the color of the ray.
 *
 * Parameters:
 *      r - The ray to calculate the color of.
 *
 * Return:
 *      The color of the ray.
 */

color ray_color(const ray &r)
{
        auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
        if (t > 0.0)
        {
                vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
                return 0.5 * color(N.x() + 1, N.y() + 1, N.z() + 1);
        }

        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main()
{

        /* Image */
        auto aspect_ratio = 16.0 / 9.0;
        int image_width = 400;

        /* Calculate the height of the image based on the aspect ratio. */
        int image_height = int(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        /* Camera */
        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (double(image_width) / image_height);
        auto camera_center = point3(0, 0, 0);

        /* Calculate the horizontal and vertical vectors of the viewport. */
        auto viewport_u = vec3(viewport_width, 0, 0);
        auto viewport_v = vec3(0, -viewport_height, 0);

        /* Calculate the delta vectors for each pixel. */
        auto pixel_delta_u = viewport_u / image_width;
        auto pixel_delta_v = viewport_v / image_height;

        /* Calculate the location of the upper-left pixel. */
        auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
        auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

        /* Render */
        std::cout << "P3\n"
                  << image_width << " " << image_height << "\n255\n";

        for (int row = 0; row < image_height; row++)
        {
                std::clog << "\rScanlines remaining: " << (image_height - row) << ' ' << std::flush;
                for (int col = 0; col < image_width; col++)
                {
                        auto pixel_center = pixel00_loc + (col * pixel_delta_u) + (row * pixel_delta_v);
                        auto ray_direction = pixel_center - camera_center;
                        ray r(camera_center, ray_direction);

                        color pixel_color = ray_color(r);
                        write_color(std::cout, pixel_color);
                }
        }

        std::clog << "\rDone.                 \n";
}