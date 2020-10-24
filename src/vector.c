/*
 * Copyright 2020 Rinwasyu
 * 
 * This file is part of ray-marching.
 * 
 * Ray-marching is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Ray-marching is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include <stdio.h>
#include <math.h>

#include "vector.h"
#include "matrix.h"
#include "macro.h"

inline vec3 Vec3(double x, double y, double z) {
	vec3 v;
	v.x = x;
	v.y = y;
	v.z = z;
	return v;
}

inline vec2 Vec2(double x, double y) {
	vec2 v;
	v.x = x;
	v.y = y;
	return v;
}

inline double len_v3(vec3 v) {
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

inline double len_v2(vec2 v) {
	return sqrt(v.x*v.x + v.y*v.y);
}

inline vec3 abs_v3(vec3 v) {
	return Vec3(MAX(v.x, -v.x), MAX(v.y, -v.y), MAX(v.z, -v.z));
}

inline vec2 abs_v2(vec2 v) {
	return Vec2(MAX(v.x, -v.x), MAX(v.y, -v.y));
}

inline vec3 sum_v3(vec3 A, vec3 B) {
	return Vec3(A.x+B.x, A.y+B.y, A.z+B.z);
}

inline vec3 diff_v3(vec3 A, vec3 B) {
	return Vec3(A.x-B.x, A.y-B.y, A.z-B.z);
}

inline vec3 prod_v3(vec3 A, vec3 B) {
	return Vec3(A.x*B.x, A.y*B.y, A.z*B.z);
}

inline vec3 norm_v3(vec3 v) {
	return Vec3(v.x/len_v3(v), v.y/len_v3(v), v.z/len_v3(v));
}

inline double innerprod_v3(vec3 A, vec3 B) {
	return A.x*B.x + A.y*B.y + A.z*B.z;
}

inline vec3 rot_v3(vec3 from, mat3 m) {
	return Vec3(
			m.m11*from.x + m.m12*from.y + m.m13*from.z,
			m.m21*from.x + m.m22*from.y + m.m23*from.z,
			m.m31*from.x + m.m32*from.y + m.m33*from.z
		);
}

inline vec3 max_v3(vec3 A, vec3 B) {
	vec3 v;
	v.x = MAX(A.x, B.x);
	v.y = MAX(A.y, B.y);
	v.z = MAX(A.z, B.z);
	return v;
}

inline vec3 min_v3(vec3 A, vec3 B) {
	vec3 v;
	v.x = MIN(A.x, B.x);
	v.y = MAX(A.y, B.y);
	v.z = MAX(A.z, B.z);
	return v;
}

inline void print_v3(vec3 v) {
	printf("(%.3lf, %.3lf, %.3lf)\n", v.x, v.y, v.z);
}