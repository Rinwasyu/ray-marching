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

#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"
void fishEyeCam(vec3 camera_pos, double roll, double pitch, double yaw, double range_roll, double range_pitch, double range_yaw, double **img, int width, int height);
void cam(vec3 camera_pos, double roll, double pitch, double yaw, double **img, int width, int height);

#endif