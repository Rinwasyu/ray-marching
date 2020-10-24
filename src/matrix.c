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

mat3 prod_m3(mat3 A, mat3 B) {
	return Mat3(
			A.m11*B.m11 + A.m12*B.m21 + A.m13*B.m31, A.m11*B.m12 + A.m12*B.m22 + A.m13*B.m32, A.m11*B.m13 + A.m12*B.m23 + A.m13*B.m33,
			A.m21*B.m11 + A.m22*B.m21 + A.m23*B.m31, A.m21*B.m12 + A.m22*B.m22 + A.m23*B.m32, A.m21*B.m13 + A.m22*B.m23 + A.m23*B.m33,
			A.m31*B.m11 + A.m32*B.m21 + A.m33*B.m31, A.m31*B.m12 + A.m32*B.m22 + A.m33*B.m32, A.m31*B.m13 + A.m32*B.m23 + A.m33*B.m33
		);
}

double determinant_m3(mat3 m) {
	return m.m11*m.m22*m.m33 + m.m12*m.m23*m.m31 + m.m13*m.m21*m.m32 - m.m13*m.m22*m.m31 - m.m12*m.m21*m.m33 - m.m11*m.m23*m.m32;
}

mat3 invert_m3(mat3 A) {
	mat3 A_cofactor = Mat3(
			A.m22*A.m33 - A.m23*A.m32, -(A.m12*A.m33 - A.m13*A.m32), A.m12*A.m23 - A.m13*A.m22,
			-(A.m21*A.m33 - A.m23*A.m31), A.m11*A.m33 - A.m13*A.m31, -(A.m11*A.m23 - A.m13*A.m21),
			A.m21*A.m32 - A.m22*A.m31, -(A.m11*A.m32 - A.m12*A.m31), A.m11*A.m22 - A.m12*A.m21
		);
	mat3 A_inverce = Mat3(
			A_cofactor.m11/determinant_m3(A), A_cofactor.m12/determinant_m3(A), A_cofactor.m13/determinant_m3(A),
			A_cofactor.m21/determinant_m3(A), A_cofactor.m22/determinant_m3(A), A_cofactor.m23/determinant_m3(A),
			A_cofactor.m31/determinant_m3(A), A_cofactor.m32/determinant_m3(A), A_cofactor.m33/determinant_m3(A)
		);
	return A_inverce;
}