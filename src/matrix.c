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

#include "matrix.h"

mat3 Mat3(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33) {
	mat3 m;
	m.m11 = m11; m.m12 = m12; m.m13 = m13;
	m.m21 = m21; m.m22 = m22; m.m23 = m23;
	m.m31 = m31; m.m32 = m32; m.m33 = m33;
	return m;
}

mat2 Mat2(double m11, double m12, double m21, double m22) {
	mat2 m;
	m.m11 = m11; m.m12 = m12;
	m.m21 = m21; m.m22 = m22;
	return m;
}