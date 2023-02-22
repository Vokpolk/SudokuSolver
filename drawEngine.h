#pragma once
#include "stdafx.h"
class CSudoku;
class CDrawEngine {
public:
	CDrawEngine();
	~CDrawEngine();

	void start();

	void draw();

	void sudokuSolution(CSudoku* sudoku);
	
private:

	RenderWindow window;
	Event event;

	CSudoku* sudoku;

};