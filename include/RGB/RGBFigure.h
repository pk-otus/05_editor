#pragma once
#include "../Color.h"
#include "../IGraphicPrimitive.h"

namespace GraphicEditor
{
	class RGBFigure : public IGraphicPrimitive
	{
	public:
		RGBFigure(color_type col) : color(col) {}

		color_type	GetColor() const			{ return color; }
		void		SetColor(color_type col)	{ color = col; }

	private:
		color_type color;
	};
}
