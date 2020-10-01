#include "vec3.h"
#include "color.h"

#include <iostream>

int main() {

	const int image_width = 256;
	const int image_height = 256;

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for(int j = image_height-1; j >= 0; --j){
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for(int i = image_width-1; i >= 0; --i){
			vec3 pixel_color(float(i)/(image_width-1), float(j)/(image_height-1), 0.25);
            write_color(std::cout, pixel_color);
		}
	}

	std::cerr << "\nDone!\n";
}
