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

#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

struct v_vec2 {
	double x;
	double y;
};

struct v_vec3 {
	double x;
	double y;
	double z;
};

typedef struct v_vec2 vec2;
typedef struct v_vec3 vec3;

vec3 Vec3(double x, double y, double z);
vec2 Vec2(double x, double y);
double len_v3(vec3 v);
double len_v2(vec2 v);
vec3 abs_v3(vec3 v);
vec2 abs_v2(vec2 v);
vec3 sum_v3(vec3 A, vec3 B);
vec3 diff_v3(vec3 A, vec3 B);
vec3 prod_v3(vec3 A, vec3 B);
vec3 norm_v3(vec3 v);
double innerprod_v3(vec3 A, vec3 B);
vec3 rot_v3(vec3 from, mat3 m);
vec3 max_v3(vec3 A, vec3 B);
vec3 min_v3(vec3 A, vec3 B);
void print_v3(vec3 v);

#endif