/* Ray class */
/*
	We define a ray as
	P(t) = A + tb where
	A:= origin
	t:= magnitude
	b:= direction
*/

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
	public:
		/* Constructors */
		ray() {}
		ray(const point3 &origin, const vec3 &direction) {orig = origin; dir = direction; }

		vec3 origin() const {return orig;}
		vec3 direction() const {return dir;}

		vec3 destination(double t) {
			return orig + t*dir;
		}

		/* Members*/
		point3 orig;
		vec3 dir;
};

#endif