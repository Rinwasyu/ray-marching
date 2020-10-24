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

#include <stdlib.h>

#include "macro.h"
#include "output.h"
#include "camera.h"
#include "vector.h"
#include "object.h"
#include "scene.h"

int main(void) {
	int width = 300;
	int height = 300;
	double **img = (double **)malloc(sizeof(double *) * height);
	for (int i = 0; i < height; i++) {
		img[i] = (double *)malloc(sizeof(double) * width);
	}
	
	scene s = Scene(scene_sdf);
	s.spheres[0] = Sphere(Vec3(0, 4, 0), 3, 0, 0, 0);
	s.spheres[1] = Sphere(Vec3(0, 2, 5), 2, 0, 0, 0);
	s.spheres_cnt = 2;
	s.boxes[0] = Box(Vec3(0, -0.25, 0), Vec3(10, 0.5, 10), 0, 0, 0);
	s.boxes[1] = Box(Vec3(7, 2.5, 0), Vec3(1, 2.5, 1), 0, 0, 0);
	s.boxes[2] = Box(Vec3(7, 5, -7), Vec3(0.1, 5, 0.1), 0, 0, 0);
	s.boxes_cnt = 3;
	s.toruses[0] = Torus(Vec3(7, 2.5, 7), Vec2(1.5, 0.8), PI/2+PI/5, -PI/3, 0);
	s.toruses_cnt = 1;
	
	vec3 camera_pos = Vec3(14, 13, 20);
	
	double roll = PI/6;
	double pitch = -PI/5;
	double yaw = 0;
	
	//fishEyeCam(&s, camera_pos, roll, pitch, yaw, PI/3, PI/3, 0, img, width, height);
	cam(&s, camera_pos, roll, pitch, yaw, img, width, height);
	
	output_image("result.pgm", img, width, height);
	
	return 0;
}