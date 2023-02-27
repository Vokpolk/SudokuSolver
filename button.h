#pragma once
#include "drawingObject.h"

class CButton : public CDrawingObject {
public:
	CButton() {}
	~CButton() {}

	void draw(RenderWindow& window) override;

private:

};