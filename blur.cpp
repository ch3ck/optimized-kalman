#include "headers/blur.h"

using namespace std;

vector < vector <float> > blur(vector < vector < float> > *grid, float blurring) {

	// initialize variables
	vector < vector <float> > window;
	vector < vector <float> > newGrid;
	vector <float> row;
	vector <float> newRow;

	int height = grid->size();
	int width = (*grid)[0].size();
	float center, corner, adjacent;

	// calculate blur factors
	center = 1.0 - blurring;
	corner = blurring / 12.0;
	adjacent = blurring / 6.0;

	int i, j;
	float val;
	
	
	// 2D vector reprenting the blur filter
	window = {{corner, adjacent, corner}, {adjacent, center, adjacent}, {corner, adjacent, corner}};

	// variables for blur calculations
	vector <int> DX = {-1, 0, 1};
	vector <int> DY = {-1, 0, 1};
	
	int dx, dy, ii, jj, new_i, new_j;
	float multiplier, newVal;

	// initialize new grid to zeros
	newGrid = zeros(height, width);

	// blur the grid and store in a new 2D vector
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			val = (*grid)[i][j];
			newVal = val;
			for (ii = 0; ii < 3; ii++) {
				dy = DY[ii];
				for (jj = 0; jj < 3; jj++) {
					dx = DX[jj];
					new_i = (i + dy + height) % height;
					new_j = (j + dx + width) % width;
					multiplier = window[ii][jj];
					newGrid[new_i][new_j] += newVal * multiplier;
				}
			}
		}
	}

	return newGrid;
}