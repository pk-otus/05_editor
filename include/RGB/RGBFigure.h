#pragma once
#include <iostream>
#include <iomanip>

#include "../FigureContainer.h"

namespace GraphicEditor
{
	class RGBFigure : public FigureContainer, public IGraphicPrimitive
	{
	public:
		RGBFigure(EnumFigure f, color_type col) : 
			FigureContainer(f), 
			color(col) {}


		color_type	GetColor() const			{ return color; }
		void		SetColor(color_type col)	{ color = col; }

		void Draw() const override
		{
			std::cout	<< "\nMy coordinates: [" << GetFigure()->GetCoordinates() 
						<< "], my color is " << std::uppercase << std::hex 
						<< std::setfill('0') << std::setw(6) << color;
		}
	private:
		
		color_type color;		
	};
}
