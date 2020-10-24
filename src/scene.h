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

#ifndef SCENE_H
#define SCENE_H

#include "object.h"

struct s_scene;
typedef struct s_scene scene;

struct s_scene {
	sphere spheres[1024];
	box boxes[1024];
	torus toruses[1024];
	int spheres_cnt;
	int boxes_cnt;
	int toruses_cnt;
	double (*sdf)();
};

scene Scene(double (*sdf)());
double scene_sdf(scene *s, vec3 p);

#endif