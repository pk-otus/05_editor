#pragma once
#include "../IGraphicPrimitiveCreator.h"
#include "ConcreteFiguresRGB.h"

namespace GraphicEditor
{
	class RGBGraphicPrimitiveCreator : public IGraphicPrimitiveCreator
	{
	public:
		const IGraphicPrimitive * CreateTriangle() const override
		{
			return new TriangleRGB(brush_color);
		}
		const IGraphicPrimitive* CreateCircle() const override
		{
			return new CircleRGB(brush_color);
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
	private:
		color_type brush_color = COLOR_BLACK;
	};
}
