#pragma once
#include <iostream>

#include "BlackAndWhiteFigure.h"
#include "../IGraphicPrimitive.h"

namespace GraphicEditor
{
	inline std::string BWColorName(bool black) { return black ? "black" : "white"; }

	class TriangleBW : public GraphicEditor::IGraphicPrimitive, BlackAndWhiteFigure
	{
	public:
		TriangleBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White triangle, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};

	class CircleBW : public IGraphicPrimitive, BlackAndWhiteFigure
	{
	public:
		CircleBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White circle, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};
}