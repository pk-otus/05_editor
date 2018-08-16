#pragma once
#include <cassert>

#include "../BasicPrimitiveCreator.h"
#include "RGBFigure.h"

namespace GraphicEditor
{
	class RGBGraphicPrimitiveCreator : public BasicPrimitiveCreator<RGBFigure>
	{
	public:
		bool TrySetBrushColor(color_type col) override
		{
			brush_color = col;
			return true; //changed
		}

		void ChangeFillColor(IGraphicPrimitive* p) override
		{
			auto rgb = dynamic_cast<RGBFigure*>(p);
			assert(rgb);

			rgb->SetColor(brush_color);
		}

	private:
		RGBFigure* CreateNewFigure(EnumFigure figure_type) const override
		{
			return new RGBFigure(figure_type, brush_color);
		}

		color_type brush_color = COLOR_BLACK;
	};
}
