#pragma once

class CDrawingObject {
public:
	CDrawingObject() {}
	virtual ~CDrawingObject() {}

	virtual void draw(RenderWindow& window) = 0;
private:

};