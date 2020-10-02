/* VEC3 class */

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
	public:
		/* constructors */
		vec3() {}
		
		vec3(double e0, double e1, double e2) { e[0] = e0; e[1] = e1; e[2] = e2; }

		/* methods */
		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }

		/* operators */
		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		double operator[](int i) const { return e[i]; }
		double& operator[](int i) { return e[i]; } 

		// vector addition
		vec3& operator+=(const vec3 &v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}

		// scalar multiplication
		vec3& operator*=(const double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}

		// scalar division
		vec3& operator/=(const double t){
			return *this *= (1/t);
		}

		// lengths
		double length() const {
			return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
		}

		double length_squared() const {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}

		/* members */
		double e[3];
};

/* type aliases */
using point3 = vec3;
using color = vec3;
// warning: alias declarations are a C++11 extension

/* vec3 utility functions */

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[1] + v.e[1]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[1] - v.e[1]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[1] * v.e[1]);
}

inline vec3 operator*(const double t, const vec3 &v) {
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, const double t) {
	return t * v;
}

inline vec3 operator/(const vec3 v, const double t) {
	return (1/t) * v;
}

// dot product
inline double dot(const vec3 &u, const vec3 &v) {
	return u.e[0] * u.e[0] + u.e[1] * u.e[1] + u.e[2] * u.e[2];
}

// cross product
inline vec3 cross(const vec3 &u, const vec3 &v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3 v) {
	return v/v.length();
}

#endif


