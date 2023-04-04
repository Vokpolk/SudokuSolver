#pragma once
#include "stdafx.h"

const int rows = 9;
const int cols = 9;

class CSudoku {
public:
	CSudoku();
	~CSudoku() {};

	void extractSudokuFile();
	void createSudokuFile();

	bool isNumFreeInRow(int num, int row);
	bool isNumFreeInCol(int num, int col);
	bool isNumFreeInBox(int num, int row, int col);

	bool isNumMissing(int& row, int& col);

	bool isNumFits(int num, int row, int col);

	bool solution();

	int getArrCell(int row, int col) { return arr[row][col]; }

	bool getTriedToSolve() { return triedToSolve; }
	void setTriedToSolve(bool triedToSolve) { this->triedToSolve = triedToSolve; }
	
private:
	int arr[rows][cols];
	bool triedToSolve;
	string dir;
};
