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

#include "ray.h"
#include "vector.h"
#include "macro.h"
#include "scene.h"
#include "color.h"

int beam_hit(scene *s, vec3 p, vec3 v, double len) {
	int split = len*50;
	
	for (int i = 0; i <= split; i++) {
		double dist = len * i / split;
		
		vec3 here = Vec3(p.x + v.x*dist, p.y + v.y*dist, p.z + v.z*dist);
		
		if (s->sdf(s, here, 0) < 0.01) {
			return 1;
		}
	}
	return 0;
}

rgb beam(scene *s, vec3 p, vec3 v, double len) {
	rgb color = Rgb(0, 0, 0);
	int split = len*50;
	
	for (int i = 0; i <= split; i++) {
		double dist = len * i / split;
		
		vec3 here = Vec3(p.x + v.x*dist, p.y + v.y*dist, p.z + v.z*dist);
		vec3 ray = norm_v3(Vec3(-1.3, -0.8, -0.5));
		
		if (s->sdf(s, here, 1) < 0.01) {
			double ep = 0.0001;
			
			vec3 normal = norm_v3(
					Vec3(
						s->sdf(s, Vec3(here.x-ep, here.y, here.z)) - s->sdf(s, Vec3(here.x+ep, here.y, here.z)),
						s->sdf(s, Vec3(here.x, here.y-ep, here.z)) - s->sdf(s, Vec3(here.x, here.y+ep, here.z)),
						s->sdf(s, Vec3(here.x, here.y, here.z-ep)) - s->sdf(s, Vec3(here.x, here.y, here.z+ep))
					)
				);
			
			rgb diffuse = Rgb(0, 0, 0);
			if (beam_hit(s, diff_v3(here, Vec3(v.x*len/split, v.y*len/split, v.z*len/split)), Vec3(-ray.x, -ray.y, -ray.z), 20) == 0){
				double brightness = MAX(innerprod_v3(normal, ray), 0);
				diffuse = Rgb(s->near_obj_color.r * brightness, s->near_obj_color.g * brightness, s->near_obj_color.b * brightness);
			}
			return diffuse;
		}
	}
	return color;
}