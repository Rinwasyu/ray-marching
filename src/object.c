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

#include "vector.h"
#include "matrix.h"
#include "object.h"

sphere spheres[16] = {0};
box boxes[16] = {0};

sphere Sphere(vec3 p, double radius) {
	sphere s;
	s.active = 1;
	s.p = p;
	s.radius = radius;
	return s;
}

box Box(vec3 p, vec3 b) {
	box o;
	o.active = 1;
	o.p = p;
	o.b = b;
	return o;
}