#include "stdafx.h"
#include "button.h"

CButton::CButton(Vector2f position, Vector2f size, string text) {
	this->position 		= position;
	this->size 			= size;
	this->text 			= text;

	textPosition.x = position.x + size.x;// / 2.0f;
    textPosition.y = position.y + size.y / 2;

    buttonClicked = false;
}

void CButton::draw(RenderWindow& window) {
	
	changeButtonColor();

	rectangle.setSize(size);
	rectangle.setFillColor(color);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(position);

	window.draw(rectangle);
	drawText(window);
}

void CButton::drawText(RenderWindow& window) {
	Font font;
    font.loadFromFile("Consolas/consolas.ttf");
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
		color = Color(130, 230, 30);
	} else {
		color = Color(252, 15, 192);
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