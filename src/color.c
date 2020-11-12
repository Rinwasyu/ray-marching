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

#include "color.h"

inline rgb Rgb(double r, double g, double b) {
	rgb color;
	color.r = r;
	color.g = g;
	color.b = b;
	return color;
}

inline rgb sum_rgb(rgb a, rgb b) {
	return Rgb(a.r + b.r, a.g + b.g, a.b + b.b);
}

inline rgb prod_rgb(rgb a, double b) {
	return Rgb(a.r * b, a.g * b, a.b * b);
}