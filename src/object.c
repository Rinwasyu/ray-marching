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

#include "object.h"
#include "vector.h"
#include "matrix.h"
#include "color.h"

inline sphere Sphere(vec3 p, double radius, double roll, double pitch, double yaw, rgb color) {
	sphere obj = {0};
	obj.active = 1;
	obj.p = p;
	obj.radius = radius;
	obj.roll = roll;
	obj.pitch = pitch;
	obj.yaw = yaw;
	obj.color = color;
	return obj;
}

inline box Box(vec3 p, vec3 b, double roll, double pitch, double yaw, rgb color) {
	box obj = {0};
	obj.active = 1;
	obj.p = p;
	obj.b = b;
	obj.roll = roll;
	obj.pitch = pitch;
	obj.yaw = yaw;
	obj.color = color;
	return obj;
}

inline torus Torus(vec3 p, vec2 t, double roll, double pitch, double yaw, rgb color) {
	torus obj = {0};
	obj.active = 1;
	obj.p = p;
	obj.t = t;
	obj.roll = roll;
	obj.pitch = pitch;
	obj.yaw = yaw;
	obj.color = color;
	return obj;
}