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

#include "sdf.h"
#include "vector.h"
#include "macro.h"

inline double sdf_sphere(vec3 v, double radius) {
	return len_v3(v) - radius;
}

inline double sdf_box(vec3 p, vec3 b) {
	vec3 q = diff_v3(abs_v3(p), b);
	return len_v3(max_v3(q, Vec3(0,0,0))) + MIN(MAX(q.x, MAX(q.y, q.z)), 0);
	//return len_v3(max_v3(diff_v3(abs_v3(p), b), Vec3(0, 0, 0)));
}

inline double sdf_torus(vec3 p, vec2 t) {
	vec2 q = Vec2(len_v2(Vec2(p.x, p.z))-t.x, p.y);
	return len_v2(q)-t.y;
}