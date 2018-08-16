#include "../include/ConcreteFigures.h"

std::string GraphicEditor::Triangle::GetCoordinates() const
{
	return "Point1, Point2, Point3";
}

std::string GraphicEditor::Square::GetCoordinates() const
{
	return "PointUpperLeft, SideLength";
}

std::string GraphicEditor::Circle::GetCoordinates() const
{
	return "PointCenter, Radius";
}

std::string GraphicEditor::Hexagon::GetCoordinates() const
{
	return "Point1, Point2, Point3 Point4, Point5, Point6";
}
