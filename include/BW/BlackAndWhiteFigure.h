#pragma once
#include <iostream>

#include "../FigureContainer.h"

namespace GraphicEditor
{
	inline std::string BWColorName(bool black) { return black ? "black" : "white"; }

	class BlackAndWhiteFigure : public FigureContainer, public IGraphicPrimitive
	{
	public:
		BlackAndWhiteFigure(EnumFigure f, bool black) : 
			FigureContainer(f),
			isBlack(black) {}

		bool IsBlack() const { return isBlack; }

		void SetWhite() { isBlack = false; }
		void SetBlack() { isBlack = true; }

		void Draw() const override
		{
			std::cout	<< "\nMy coordinates: [" << GetFigure()->GetCoordinates() 
						<< "], my color is " << BWColorName(IsBlack());
		}
	private:
		bool isBlack;
	};
}
