#include "headers/sense.h"

using namespace std;

vector< vector <float> > sense(char color, vector< vector <char> > *grid, vector< vector <float> > *beliefs,  float p_hit, float p_miss) 
{
	vector< vector <float> > newGrid;
	vector<float> row, newRow;
	float prior, p;
	char cell;
	int i, j, height, width;
	
	height = grid->size();
	width = (*grid).size();
	
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			prior = (*beliefs)[i][j];
			cell = (*grid)[i][j];
			if (cell == color) {
				p = prior * p_hit;
			} else {
				p = prior * p_miss;
			}
			
			(*beliefs)[i][j] = p;
		}
	}
	return *beliefs;
}
