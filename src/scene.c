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
			min_dist = MIN(sdf_sphere(diff_v3(s->spheres[i].p, p), s->spheres[i].radius), min_dist);
		}
	}
	
	for (int i = 0; i < s->boxes_cnt; i++) {
		if (s->boxes[i].active) {
			min_dist = MIN(sdf_box(diff_v3(s->boxes[i].p, p), s->boxes[i].b), min_dist);
		}
	}
	
	for (int i = 0; i < s->toruses_cnt; i++) {
		if (s->toruses[i].active) {
			min_dist = MIN(sdf_torus(diff_v3(s->toruses[i].p, p), s->toruses[i].t), min_dist);
		}
	}
	
	return min_dist;
}