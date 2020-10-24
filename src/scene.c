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

#include <math.h>

#include "scene.h"
#include "vector.h"
#include "macro.h"
#include "sdf.h"

scene Scene(double (*sdf)()) {
	scene s = {0};
	s.sdf = sdf;
	return s;
}

double scene_sdf(scene *s, vec3 p) {
	double min_dist = INF;
	for (int i = 0; i < s->spheres_cnt; i++) {
		if (s->spheres[i].active) {
			mat3 r_x = Mat3(
					1, 0, 0,
					0, cos(s->spheres[i].roll), sin(s->spheres[i].roll),
					0, -sin(s->spheres[i].roll), cos(s->spheres[i].roll)
				);
			mat3 r_y = Mat3(
					cos(s->spheres[i].pitch), 0, -sin(s->spheres[i].pitch),
					0, 1, 0,
					sin(s->spheres[i].pitch), 0, cos(s->spheres[i].pitch)
				);
			mat3 r_z = Mat3(
					cos(s->spheres[i].yaw), sin(s->spheres[i].yaw), 0,
					-sin(s->spheres[i].yaw), cos(s->spheres[i].yaw), 0,
					0, 0, 1
				);
			min_dist = MIN(sdf_sphere(rot_v3(diff_v3(s->spheres[i].p, p), invert_m3(prod_m3(prod_m3(r_z, r_y), r_x))), s->spheres[i].radius), min_dist);
		}
	}
	
	for (int i = 0; i < s->boxes_cnt; i++) {
		if (s->boxes[i].active) {
			mat3 r_x = Mat3(
					1, 0, 0,
					0, cos(s->boxes[i].roll), sin(s->boxes[i].roll),
					0, -sin(s->boxes[i].roll), cos(s->boxes[i].roll)
				);
			mat3 r_y = Mat3(
					cos(s->boxes[i].pitch), 0, -sin(s->boxes[i].pitch),
					0, 1, 0,
					sin(s->boxes[i].pitch), 0, cos(s->boxes[i].pitch)
				);
			mat3 r_z = Mat3(
					cos(s->boxes[i].yaw), sin(s->boxes[i].yaw), 0,
					-sin(s->boxes[i].yaw), cos(s->boxes[i].yaw), 0,
					0, 0, 1
				);
			min_dist = MIN(sdf_box(rot_v3(diff_v3(s->boxes[i].p, p), invert_m3(prod_m3(prod_m3(r_z, r_y), r_x))), s->boxes[i].b), min_dist);
		}
	}
	
	for (int i = 0; i < s->toruses_cnt; i++) {
		if (s->toruses[i].active) {
			mat3 r_x = Mat3(
					1, 0, 0,
					0, cos(s->toruses[i].roll), sin(s->toruses[i].roll),
					0, -sin(s->toruses[i].roll), cos(s->toruses[i].roll)
				);
			mat3 r_y = Mat3(
					cos(s->toruses[i].pitch), 0, -sin(s->toruses[i].pitch),
					0, 1, 0,
					sin(s->toruses[i].pitch), 0, cos(s->toruses[i].pitch)
				);
			mat3 r_z = Mat3(
					cos(s->toruses[i].yaw), sin(s->toruses[i].yaw), 0,
					-sin(s->toruses[i].yaw), cos(s->toruses[i].yaw), 0,
					0, 0, 1
				);
			min_dist = MIN(sdf_torus(rot_v3(diff_v3(s->toruses[i].p, p), invert_m3(prod_m3(prod_m3(r_z, r_y), r_x))), s->toruses[i].t), min_dist);
		}
	}
	
	return min_dist;
}