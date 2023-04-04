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
	void drawSudokuField();

	void sudokuSolution(CSudoku* sudoku);
	
private:

	RenderWindow window;
	Event event;

	CSudoku* sudoku;
	CButton* button;
	CSudokuField* sudokuField;

	Text res;
	Font font;
    Text textArr[81];
	string dir;

};
