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

#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"

struct o_sphere {
	int active;
	vec3 p;
	double radius;
};

struct o_box {
	int active;
	vec3 p;
	vec3 b;
};

typedef struct o_sphere sphere;
typedef struct o_box box;

extern sphere spheres[16];
extern box boxes[16];

sphere Sphere(vec3 p, double radius);
box Box(vec3 p, vec3 b);

#endif