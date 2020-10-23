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
#include "sdf.h"
#include "object.h"

int beam_hit(vec3 p, vec3 v, double len) {
	int split = len*200;
	
	for (int i = 0; i <= split; i++) {
		double dist = len * i / split;
		
		vec3 here = Vec3(p.x + v.x*dist, p.y + v.y*dist, p.z + v.z*dist);
		
		for (int i = 0; i < 16; i++) {
			if (spheres[i].active) {
				vec3 to_ball = diff_v3(spheres[i].p, here);
				
				if (sdf_sphere(to_ball, spheres[i].radius) < 0.01) {
					return 1;
				}
			}
		}
		
		for (int i = 0; i < 16; i++) {
			if (boxes[i].active) {
				vec3 to_box = diff_v3(boxes[i].p, here);
				
				if (sdf_box(to_box, boxes[i].b) < 0.01) {
					return 1;
				}
			}
		}
	}
	return 0;
}

double beam(vec3 p, vec3 v, double len) {
	int split = len*200;
	
	for (int i = 0; i <= split; i++) {
		double dist = len * i / split;
		
		vec3 here = Vec3(p.x + v.x*dist, p.y + v.y*dist, p.z + v.z*dist);
		vec3 ray = norm_v3(Vec3(-1.3, -0.8, 0.1));
		
		for (int i = 0; i < 16; i++) {
			if (spheres[i].active) {
				vec3 to_ball = diff_v3(spheres[i].p, here);
				
				if (sdf_sphere(to_ball, spheres[i].radius) < 0.01) {
					double ep = 0.001;
					
					vec3 normal;
					normal = norm_v3(
							Vec3(
								sdf_sphere(Vec3(to_ball.x + ep, to_ball.y, to_ball.z), spheres[i].radius) - sdf_sphere(Vec3(to_ball.x - ep, to_ball.y, to_ball.z), spheres[i].radius),
								sdf_sphere(Vec3(to_ball.x, to_ball.y + ep, to_ball.z), spheres[i].radius) - sdf_sphere(Vec3(to_ball.x, to_ball.y - ep, to_ball.z), spheres[i].radius),
								sdf_sphere(Vec3(to_ball.x, to_ball.y, to_ball.z + ep), spheres[i].radius) - sdf_sphere(Vec3(to_ball.x, to_ball.y, to_ball.z - ep), spheres[i].radius)
							)
						);
					double diffuse = 0;
					if (beam_hit(diff_v3(here, Vec3(v.x*len/split, v.y*len/split, v.z*len/split)), Vec3(-ray.x, -ray.y, -ray.z), 20) == 0){
						diffuse = MAX(innerprod_v3(normal, ray), 0);
					}
					double ambient = 0.05;
					double specular = 0;
					//specular = innerprod_v3(norm_v3(sum_v3(norm_v3(to_ball), ray)), normal);
					double color = ambient + diffuse + specular;
					return (color > 1 ? 1 : color);
				}
			}
		}
		
		for (int i = 0; i < 16; i++) {
			if (boxes[i].active) {
				vec3 to_box = diff_v3(boxes[i].p, here);
		
				if (sdf_box(to_box, boxes[i].b) < 0.01) {
					double ep = 0.001;
			
					vec3 normal;
					normal = norm_v3(
							Vec3(
								sdf_box(Vec3(to_box.x + ep, to_box.y, to_box.z), boxes[i].b) - sdf_box(Vec3(to_box.x - ep, to_box.y, to_box.z), boxes[i].b),
								sdf_box(Vec3(to_box.x, to_box.y + ep, to_box.z), boxes[i].b) - sdf_box(Vec3(to_box.x, to_box.y - ep, to_box.z), boxes[i].b),
								sdf_box(Vec3(to_box.x, to_box.y, to_box.z + ep), boxes[i].b) - sdf_box(Vec3(to_box.x, to_box.y, to_box.z - ep), boxes[i].b)
							)
						);
					double diffuse = 0;
					if (beam_hit(diff_v3(here, Vec3(v.x*len/split, v.y*len/split, v.z*len/split)), Vec3(-ray.x, -ray.y, -ray.z), 20) == 0){
						diffuse = MAX(innerprod_v3(normal, ray), 0);
					}
					double ambient = 0.05;
					double specular = 0;
					//specular = innerprod_v3(norm_v3(sum_v3(norm_v3(to_ball), ray)), normal);
					double color = ambient + diffuse + specular;
					return (color > 1 ? 1 : color);
				}
			}
		}
	}
	return 0;
}