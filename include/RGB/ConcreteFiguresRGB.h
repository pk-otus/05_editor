#pragma once
#include <iostream>

#include "RGBFigure.h"
#include "../IGraphicPrimitive.h"

namespace GraphicEditor
{
	class TriangleRGB : RGBFigure, public IGraphicPrimitive
	{
	public:
		TriangleRGB(color_type col) : RGBFigure(col) {}
		void Draw() const override 
		{ 
			std::cout << "I am RGB triangle, my color is " << std::hex << GetColor() << '\n'; 
		}
	};

	class CircleRGB : RGBFigure, public IGraphicPrimitive
	{
	public:
		CircleRGB(color_type col) : RGBFigure(col) {}
		void Draw() const override
		{
			std::cout << "I am RGB circle, my color is " << std::hex << GetColor() << '\n';
		}
	};
	class SquareRGB : RGBFigure, public IGraphicPrimitive
	{
	public:
		SquareRGB(color_type col) : RGBFigure(col) {}
		void Draw() const override
		{
			std::cout << "I am RGB square, my color is " << std::hex << GetColor() << '\n';
		}
	};

	class HexagonRGB : RGBFigure, public IGraphicPrimitive
	{
	public:
		HexagonRGB(color_type col) : RGBFigure(col) {}
		void Draw() const override
		{
			std::cout << "I am RGB hexagon, my color is " << std::hex << GetColor() << '\n';
		}
	};
}
