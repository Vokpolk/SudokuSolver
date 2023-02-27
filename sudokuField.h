#pragma once
#include "drawingObject.h"

class CSudokuField : public CDrawingObject {
public:
	CSudokuField() {}
	~CSudokuField() {}

	void draw(RenderWindow& window) override;

private:
};