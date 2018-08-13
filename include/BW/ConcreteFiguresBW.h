#pragma once
#include <iostream>

#include "BlackAndWhiteFigure.h"

namespace GraphicEditor
{
	inline std::string BWColorName(bool black) { return black ? "black" : "white"; }

	class TriangleBW : public BlackAndWhiteFigure
	{
	public:
		TriangleBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White triangle, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};

	class CircleBW : public BlackAndWhiteFigure
	{
	public:
		CircleBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White circle, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};
	class SquareBW : public BlackAndWhiteFigure
	{
	public:
		SquareBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White square, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};

	class HexagonBW : public BlackAndWhiteFigure
	{
	public:
		HexagonBW(bool bw) : BlackAndWhiteFigure(bw) {}
		void Draw() const override {
			std::cout << "I am Black/White hexagon, my color is "
				<< BWColorName(IsBlack()) << '\n';
		}
	};
}