#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <iostream>

/* 
	A sphere of radius R has an equation of x^2+y^2+z^2 = R^2
	That is to say for any point (x,y,z) inside the sphere we have x^2 + y^2 + z^2 < R^2, and conversely for outside the sphere
	For any sphere at center (C_x, C_y, C_z), the equation is (x - C_x)^2 + (y - C_y)^2 + (z - C_z)^2 = r^2
	Note that the vector from an origin P = (x, y, z) to C is (P - C).
	It follows that (x - C_x)^2 + (y - C_y)^2 + (z - C_z)^2 = (P - C) \dot (P - C)
	So the equation of a sphere in vector form is (P - C) \dot (P - C) = r^2

	If we're trying to see if a ray ever hits a sphere, we simply need to see if the ray at any point t satisfies the equation above
	Therefore we solve for (P(t) - C) \dot (P(t) - C) = r^2
	Expanding we have (A + tb - C) \dot (A + tb - C) = r^
	With some vector algebra we get t^2(b \dot b) + 2tb \dot (A - C) + (A - C) \dot (A - C) - r^2 = 0
	It suffices then to solve the quadratic for t
*/

// checks if a ray &r hits a sphere with &center and radius r 
bool hit_sphere(const point3 &center, double radius, const ray& r){
	vec3 AC = r.origin() - center;
	auto a = dot(r.direction(), r.direction());
	auto b = 2.0 * dot(AC, r.direction());
	auto c = dot(AC, AC) - radius*radius;
	auto discriminant = b*b - 4*a*c;
	return (discriminant > 0);
}

// this takes a ray and determines the color to be displayed in the pixel
color ray_color(const ray& r) {
	if(hit_sphere(point3(0, 0, -1), 0.5, r)){
		return color(1, 0, 0);
	}
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for(int j = image_height-1; j >= 0; --j){
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for(int i = 0; i < image_width; ++i){
            auto u = double(i) / (image_width-1);
            auto v = double(j) / (image_height-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);
           	write_color(std::cout, pixel_color);
		}
	}

	std::cerr << "\nDone!\n";
}
