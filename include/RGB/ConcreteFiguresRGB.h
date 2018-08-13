#pragma once
#include <iostream>

#include "RGBFigure.h"

namespace GraphicEditor
{
	class TriangleRGB : public RGBFigure
	{
	public:
		TriangleRGB(color_type col) : RGBFigure(col) {}
		void Draw() const override 
		{ 
			std::cout << "I am RGB triangle, my color is " << std::hex << GetColor() << '\n'; 
		}
	};

	class CircleRGB : public RGBFigure
	{
	public:
		CircleRGB(color_type col) : RGBFigure(col) {}
		void Draw() const override
		{
			std::cout << "I am RGB circle, my color is " << std::hex << GetColor() << '\n';
		}
	};
	class SquareRGB : public RGBFigure
	{
	public:
		SquareRGB(color_type col) : RGBFigure(col) {}
		void Draw() const override
		{
			std::cout << "I am RGB square, my color is " << std::hex << GetColor() << '\n';
		}
	};

	class HexagonRGB : public RGBFigure
	{
	public:
		HexagonRGB(color_type col) : RGBFigure(col) {}
		void Draw() const override
		{
			std::cout << "I am RGB hexagon, my color is " << std::hex << GetColor() << '\n';
		}
	};
}
