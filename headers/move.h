#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <iostream>
#include "zeros.h"

std::vector< std::vector <float> > move(int dy, int dx, 
	std::vector < std::vector <float> > *beliefs); 

#endif /* MOVE.H */
