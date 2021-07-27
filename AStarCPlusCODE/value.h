#pragma once
#include<iostream>
using namespace std;

struct Node {
	int finalCost;
	// Heuristic cost of the current cell public 
	int heuristicCost;

	// coordinates public 
	int i, j;
	// parent cell for path public 
	
	/*Node(int val) {
		finalCost = val;
		left = NULL;
		right = NULL;
	}*/

};
typedef Node* NODE;