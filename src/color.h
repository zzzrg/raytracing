/* Color class */
/*
	Things I had to google

*/ 

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

// this writes a single pixel's color to the image
void write_color(std::ostream &out, vec3 pixel_color) {
	out << static_cast<int>(255.999 * pixel_color.x()) << ' ' 
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}


#endif