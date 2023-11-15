#pragma once

#include "vec3.h"
#include "point3.h"

class ray {
private:
	// Origin
	point3 A;
	// direction
	vec3 b;
public:

	ray(const point3& origin, const vec3& dir): A(origin), b(dir) {
	}

	point3 at(const double& t) const {
		return  A + b * t;
	}

	point3 origin() const {
		return A;
	}

	vec3 dir() const {
		return b;
	}

	color ray_color() {
		vec3 unit_direction = unit_vector(b);
		auto a = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
	}

};