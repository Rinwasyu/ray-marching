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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>

#include "macro.h"
#include "output.h"
#include "camera.h"
#include "object.h"

int main(void) {
	int width = 1000;
	int height = 1000;
	double **img = (double **)malloc(sizeof(double *) * height);
	for (int i = 0; i < height; i++) {
		img[i] = (double *)malloc(sizeof(double) * width);
	}
	
	spheres[0] = Sphere(Vec3(0, 4, 0), 3);
	spheres[1] = Sphere(Vec3(0, 2, 5), 2);
	boxes[0] = Box(Vec3(0, 0, 0), Vec3(10, 0.5, 10));
	boxes[1] = Box(Vec3(5, 0, 5), Vec3(1, 5, 1));
	boxes[2] = Box(Vec3(7, 0, -7), Vec3(0.1, 10, 0.1));
	
	vec3 camera_pos = Vec3(14, 13, 20);
	
	//vec3 camera_pos = Vec3(0, 30, 0);
	double roll = PI/6;
	double pitch = -PI/5;
	double yaw = 0;
	
	//fishEyeCam(camera_pos, roll, pitch, yaw, PI/3, PI/3, 0, img, width, height);
	cam(camera_pos, roll, pitch, yaw, img, width, height);
	
	output_image("result.pgm", img, width, height);
	
	return 0;
}