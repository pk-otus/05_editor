#pragma once
#include "GraphicEditor.h"

namespace GraphicEditor
{
	class Triangle : public AbstractFigure
	{
	public:
		std::string GetCoordinates() const override;
	};
	class Square : public AbstractFigure
	{
	public:
		std::string GetCoordinates() const override;
	};
	class Circle : public AbstractFigure
	{
	public:
		std::string GetCoordinates() const override;
	};
	class Hexagon : public AbstractFigure
	{
	public:
		std::string GetCoordinates() const override;
	};
}