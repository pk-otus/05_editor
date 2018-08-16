#pragma once
#include "GraphicEditor.h"
#include "ConcreteFigures.h"

namespace GraphicEditor
{
	class FigureContainer
	{
	public:
		FigureContainer(EnumFigure f) : fig(CreateFigure(f)) {}

		~FigureContainer()
		{
			delete fig;
		}
		const AbstractFigure* GetFigure() const { return fig; }

		void ChangeFigure(EnumFigure f)
		{
			delete fig;
			fig = CreateFigure(f);
		}
	private:
		static AbstractFigure* CreateFigure(EnumFigure figure_type)
		{
			switch (figure_type)
			{
			case EnumFigure::Triangle:	return new Triangle();
			case EnumFigure::Square:	return new Square();
			case EnumFigure::Hexagon:	return new Hexagon();
			case EnumFigure::Circle:	return new Circle();
			default:
				throw std::logic_error("unsupported figure");
			}
		}

		AbstractFigure * fig;
	};
}
