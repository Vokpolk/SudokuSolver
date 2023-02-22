#pragma once
#include "stdafx.h"

const int rows = 9;
const int cols = 9;

class CSudoku {
public:
	void extractSudokuFile();
	void createSudokuFile();

	bool isNumFreeInRow(int num, int row);
	bool isNumFreeInCol(int num, int col);
	bool isNumFreeInBox(int num, int row, int col);

	bool isNumMissing(int& row, int& col);

	bool isNumFits(int num, int row, int col);

	bool solution();
	
	int arr[rows][cols];

private:
};