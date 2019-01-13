#include "headers/initialize_beliefs.h"

using namespace std;

vector< vector <float> > initialize_beliefs(vector< vector <char> > *grid) {
	
	// initialize variables for new grid
	vector< vector <float> > newGrid;
	vector<float> newRow;
	int i, j, height, width, area;
	float total, prob_per_cell;
	
	height = grid->size();
	width = (*grid)[0].size();
	
	// calculate initial grid values
	prob_per_cell = 1.0 / (height * width);
	for (j = 0; j < width; j++) {
		newRow.push_back(prob_per_cell);
	}
	
	// store initial values in a new 2D grid with same size as grid
	for ( i = 0; i < height; i++) {
		newGrid.push_back(newRow);
	}
	return newGrid;
}