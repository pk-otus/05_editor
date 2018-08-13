#pragma once
#include "../Color.h"

namespace GraphicEditor
{
	class RGBFigure
	{
	public:
		RGBFigure(color_type col) : color(col) {}

		color_type GetColor() const { return color; }
	private:
		color_type color;
	};
}
