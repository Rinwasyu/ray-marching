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
#include <math.h>
#include <omp.h>

#include "camera.h"
#include "ray.h"
#include "vector.h"
#include "color.h"

void fishEyeCam(scene *s, vec3 camera_pos, double roll, double pitch, double yaw, double range_roll, double range_pitch, double range_yaw, rgb **img, int width, int height) {
	int cnt = 0;
	
	scene s_cpy = *s;
	#pragma omp parallel for firstprivate(s_cpy)// num_threads(32)
	for (int i = 0; i < height; i++) {
		double beam_roll = roll - range_roll/2 + i*range_roll/height;
		for (int j = 0; j < width; j++) {
			double beam_pitch = pitch - range_pitch/2 + j*range_pitch/width;
			double beam_yaw = yaw;
			vec3 angle = Vec3(0, 0, -1);
			mat3 r_x = Mat3(
					1, 0, 0,
					0, cos(beam_roll), sin(beam_roll),
					0, -sin(beam_roll), cos(beam_roll)
				);
			mat3 r_y = Mat3(
					cos(beam_pitch), 0, -sin(beam_pitch),
					0, 1, 0,
					sin(beam_pitch), 0, cos(beam_pitch)
				);
			mat3 r_z = Mat3(
					cos(beam_yaw), sin(beam_yaw), 0,
					-sin(beam_yaw), cos(beam_yaw), 0,
					0, 0, 1
				);
			rgb color = beam(&s_cpy, camera_pos, norm_v3(rot_v3(rot_v3(rot_v3(angle, r_x), r_y), r_z)), 50, 10);
			img[i][j] = color;
			//printf("%s", color > 0 ? "#" : " ");
			cnt++;
		}
		//printf("\n");
		printf("\e[Hgenerating...(%d%%)", (int)((double)cnt/width/height*100));
		fflush(stdout);
	}
}

void cam(scene *s, vec3 camera_pos, double roll, double pitch, double yaw, rgb **img, int width, int height) {
	mat3 r_x = Mat3(
			1, 0, 0,
			0, cos(roll), sin(roll),
			0, -sin(roll), cos(roll)
		);
	mat3 r_y = Mat3(
			cos(pitch), 0, -sin(pitch),
			0, 1, 0,
			sin(pitch), 0, cos(pitch)
		);
	mat3 r_z = Mat3(
			cos(yaw), sin(yaw), 0,
			-sin(yaw), cos(yaw), 0,
			0, 0, 1
		);
	
	int cnt = 0;
	scene s_cpy = *s;
	#pragma omp parallel for firstprivate(s_cpy)
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			double sx = -2+j*4.0/width;
			double sy = 2-i*4.0/height;
			
			img[i][j] = beam(&s_cpy, camera_pos, norm_v3(rot_v3(rot_v3(rot_v3(Vec3(sx, sy, -4), r_x), r_y), r_z)), 40, 10);
		}
		cnt += width;
		printf("\rrendering... %d/%d (%d%%)", cnt, width*height, (int)((double)cnt/width/height*100));
		fflush(stdout);
	}
}