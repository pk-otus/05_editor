#pragma once
#include <iostream>

#include "BlackAndWhiteFigure.h"
#include "../IGraphicPrimitive.h"

namespace GraphicEditor
{
	inline std::string BWColorName(bool black) { return black ? "black" : "white"; }

	class TriangleBW : BlackAndWhiteFigure, public IGraphicPrimitive
	{
	public:
		TriangleBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White triangle, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};

	class CircleBW : BlackAndWhiteFigure, public IGraphicPrimitive
	{
	public:
		CircleBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White circle, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};
	class SquareBW : BlackAndWhiteFigure, public IGraphicPrimitive
	{
	public:
		SquareBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White square, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};

	class HexagonBW : BlackAndWhiteFigure, public IGraphicPrimitive
	{
	public:
		HexagonBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White hexagon, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};
}