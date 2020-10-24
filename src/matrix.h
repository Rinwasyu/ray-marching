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

#ifndef MATRIX_H
#define MATRIX_H

struct m_mat2 {
	double m11; double m12;
	double m21; double m22;
};

struct m_mat3 {
	double m11; double m12; double m13;
	double m21; double m22; double m23;
	double m31; double m32; double m33;
};

typedef struct m_mat2 mat2;
typedef struct m_mat3 mat3;

mat3 Mat3(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33);
mat2 Mat2(double m11, double m12, double m21, double m22);
mat3 prod_m3(mat3 A, mat3 B);
mat3 invert_m3(mat3 m);

#endif