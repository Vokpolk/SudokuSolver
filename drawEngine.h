#pragma once
#include "stdafx.h"
class CSudoku;
class CButton;
class CSudokuField;

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
	CButton* button;
	CSudokuField* sudokuField;

	Text res;
    Text textArr[81];

};