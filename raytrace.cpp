#include <iostream>

#include "vec3.h"
#include "color.h"

int main()
{
        const int image_width = 256;
        const int image_height = 256;

        std::cout << "P3\n"
                  << image_width << " " << image_height << "\n"
                  << "255\n ";

        for (int col = 0; col < image_height; ++col)
        {
                std::clog << "\rScanlines remaining: " << (image_height - col) << ' ' << std::flush;

                for (int row = 0; row < image_width; ++row)
                {
                        color pixel_color(double(row) / (image_width - 1),
                                          double(col) / (image_height - 1),
                                          0.25);
                        write_color(std::cout, pixel_color);
                }
        }

        std::clog << "\rDone.                 \n";

        return 0;
}