#pragma once
#include "drawingObject.h"

class CButton : public CDrawingObject {
public:	
	CButton(Vector2f position, Vector2f size, string text);
	~CButton() {}

	void draw(RenderWindow& window) override;
	void drawText(RenderWindow& window);

	void leftClickHandle(Vector2i position, bool pressed);

//temp function
	void changeButtonColor();

	bool pointIsMine(Vector2i position/*, Event event*/);

private:
	RectangleShape 	rectangle;
	Vector2f 		position;
	Vector2f 		size;
	Color			color;

	string			text;
	Vector2f		textPosition;
	Color			textColor;

	bool			buttonClicked;
};