#include "headers/initialize_beliefs.h"

using namespace std;

vector< vector <float> > initialize_beliefs(vector< vector <char> > *grid) {

	// initialize variables for new grid
	float height = grid->size();
	float width = (*grid)[0].size();
	float prob_per_cell = 1.0 / (height * width);
	
	vector<float> newRow(width, prob_per_cell);
	vector< vector <float> > newGrid(height, newRow);
	return newGrid;
}