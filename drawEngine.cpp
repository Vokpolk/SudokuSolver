#include "stdafx.h"
#include "solution.h"
#include "sudokuField.h"
#include "button.h"
#include "drawEngine.h"

CDrawEngine::CDrawEngine() {
	window.create(VideoMode(550, 550), "Sudoku solver");
    start();
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
    //заготовка для кнопки
    Vector2f buttonPosition(210.f, 20.f);
    Vector2f buttonSize(120.f, 40.f);
    button = new CButton(buttonPosition, buttonSize, "Press to solve");
    sudokuField = new CSudokuField;

    //решение судоку
    sudoku = new CSudoku;
    sudoku->extractSudokuFile();
    //sudokuSolution(sudoku);

    draw();	
}

void CDrawEngine::draw() {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        //draw sudoku
        window.draw(res);
        for (int i = 0; i < 81; i++) {
            window.draw(textArr[i]);
        }

        //draw button
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == Mouse::Left) {
                button->leftClickHandle(Mouse::getPosition(window), true);
            }
        }
        if (event.type == Event::MouseButtonReleased) {
            if (event.mouseButton.button == Mouse::Left) {
                button->leftClickHandle(Mouse::getPosition(window), false);
                if (button->pointIsMine(Mouse::getPosition(window))) {
                    if (!sudoku->getTriedToSolve()) {
                        sudokuSolution(sudoku);
                        sudoku->setTriedToSolve(true);
                    }
                }
            }
        }

        drawSudokuField();
        button->draw(window);

        //draw window
        window.display();
        window.clear(Color(0,0,0,0));
    }
}

void CDrawEngine::drawSudokuField() {
    //вывод результата
    font.loadFromFile("Consolas/consolas.ttf");

    //создаём текст
    res.setFont(font);
    res.setString("Result:");
    res.setPosition(100, 100 - 40);
    res.setCharacterSize(30);
    res.setFillColor(Color::White);

    int count = 0;
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