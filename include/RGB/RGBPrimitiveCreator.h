#pragma once
#include "../IGraphicPrimitiveCreator.h"
#include "ConcreteFiguresRGB.h"

namespace GraphicEditor
{
	class RGBGraphicPrimitiveCreator : public IGraphicPrimitiveCreator
	{
	public:
		IGraphicPrimitive * CreateTriangle() const override
		{
			return new TriangleRGB(brush_color);
		}
		IGraphicPrimitive* CreateCircle() const override
		{
			return new CircleRGB(brush_color);
		}
		IGraphicPrimitive* CreateSquare() const override
		{
			return new SquareRGB(brush_color);
		}
		IGraphicPrimitive* CreateHexagon() const override
		{
			return new HexagonRGB(brush_color);
		}
		void DeletePrimitive(const IGraphicPrimitive* p) const override
		{
			delete p;
		}

		bool TrySetBrushColor(color_type col) override
		{
			brush_color = col;
			return true; //changed
		}

		void ChangeFillColor(IGraphicPrimitive* p) const override
		{
			auto rgb = dynamic_cast<RGBFigure*>(p);
			assert(rgb);

			rgb->SetColor(brush_color);
		}
	private:
		color_type brush_color = COLOR_BLACK;
	};
}
