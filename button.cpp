#include "stdafx.h"
#include "button.h"

CButton::CButton(Vector2f position, Vector2f size, string text) {
	this->position 		= position;
	this->size 			= size;
	this->text 			= text;

	textPosition.x = position.x + size.x;
    textPosition.y = position.y + size.y / 2;

    buttonClicked = false;
    color = Color(150, 150, 150);

	dir = "/Users/vokpolk/Documents/Programming/C++/SudokuSolver/";
}

void CButton::draw(RenderWindow& window) {
	
	changeButtonColor();

	rectangle.setSize(size);
	rectangle.setFillColor(color);
	rectangle.setOutlineThickness(1);
	rectangle.setPosition(position);

	window.draw(rectangle);
	drawText(window);
}

void CButton::drawText(RenderWindow& window) {
	Font font;
    font.loadFromFile(dir + "Consolas/consolas.ttf");
    //создаём текст
    Text text(this->text, font);
    FloatRect bounds = text.getLocalBounds();
    text.setPosition(textPosition.x - bounds.width / 2, textPosition.y - 10.f);
    text.setCharacterSize(15);
    text.setFillColor(Color::White);
    //рисуем это
    window.draw(text);
}

void CButton::changeButtonColor() {
	if (buttonClicked) {
		color = Color(200, 200, 200);
	} else {
		color = Color(150, 150, 150);
	}
}

void CButton::leftClickHandle(Vector2i position, bool pressed) {
	if (pressed && pointIsMine(position)) {
		buttonClicked = true;
	} else if (!pressed) {
		buttonClicked = false;
	}
}

bool CButton::pointIsMine(Vector2i position/*, Event event*/) {
	if ((position.x >= this->position.x 
		&& position.x <= this->position.x + this->size.x) 
		&& (position.y >= this->position.y 
		&& position.y <= this->position.y + this->size.y) /*&&
        (event.type == Event::MouseButtonPressed)*/) {
		return true;	
	}
		
	return false;
}
