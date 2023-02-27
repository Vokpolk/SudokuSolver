#include "stdafx.h"
#include "solution.h"
#include "sudokuField.h"
#include "button.h"
#include "drawEngine.h"

CDrawEngine::CDrawEngine() {
	window.create(VideoMode(550, 550), "Sudoku solver");
}

CDrawEngine::~CDrawEngine() {
    if (button != nullptr) {
        delete button;
        button = nullptr;
    }

    if (sudokuField != nullptr) {
        delete sudokuField;
        sudokuField = nullptr;
    }

    if (sudoku != nullptr) {
        delete sudoku;
        sudoku = nullptr;
    }
}

void CDrawEngine::start() {
    //
    button = new CButton;
    sudokuField = new CSudokuField;

    //решение судоку
    sudoku = new CSudoku;
    sudokuSolution(sudoku);

    //вывод результата
    Font font;
    font.loadFromFile("Consolas/consolas.ttf");

    //создаём текст
    Text res;
    res.setFont(font);
    res.setString("Result:");
    res.setPosition(100, 100 - 40);
    res.setCharacterSize(30);
    res.setFillColor(Color::White);

    int count = 0;
    Text textArr[81];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            textArr[count].setFont(font);
            textArr[count].setString(to_string(sudoku->getArrCell(i, j)));
            textArr[count].setPosition(100 + j * 40, 100 + i * 40);
            textArr[count].setCharacterSize(30);
            textArr[count].setFillColor(Color::White);
            count++;
        }
    }

	while (window.isOpen()) {
        while (window.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                window.close();
        	}
            if (event.key.code == Keyboard::Escape) {
                window.close();
            }
        }
        draw();
        window.draw(res);
        for (int i = 0; i < 81; i++) {
            window.draw(textArr[i]);
        }

		window.display();
    	window.clear(Color(0,0,0,0));
    }
}

void CDrawEngine::draw() {

}

void CDrawEngine::sudokuSolution(CSudoku* sudoku) {
    sudoku->extractSudokuFile();
    if (sudoku->solution()) {
        cout << "Solution is in \"res.txt\" file" << endl;
        sudoku->createSudokuFile();
    } else {
        cout << "No solution!" << endl;
    }
}






