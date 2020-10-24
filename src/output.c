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

void output_image(char *filename, double **img, int width, int height) {
	FILE *fp;
	if ((fp = fopen(filename, "wb")) == NULL) {
		printf("failed to save\n");
	}
	
	fprintf(fp, "P2\n# @Rinwasyu yay HAHAHA\n");
	fprintf(fp, "%d %d\n", width, height);
	fprintf(fp, "10000\n");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fprintf(fp, "%d ", (int)(img[i][j]*10000));
		}
		fprintf(fp, "\n");
	}
	
	fclose(fp);
}