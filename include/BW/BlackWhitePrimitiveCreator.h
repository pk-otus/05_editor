#pragma  once
#include <cassert>

#include "../BasicPrimitiveCreator.h"
#include "BlackAndWhiteFigure.h"

namespace GraphicEditor
{
	class BlackWhiteGraphicPrimitiveCreator : public BasicPrimitiveCreator<BlackAndWhiteFigure>
	{
	public:
		bool TrySetBrushColor(color_type col) override
		{
			switch (col)
			{
			case COLOR_BLACK:
				isBlackBrhush = true;
				break;
			case COLOR_WHITE:
				isBlackBrhush = false;
				break;
			default:
				return false; //not changed
			}
			return true; //changed
		}
		void ChangeFillColor(IGraphicPrimitive* p) override
		{
			auto bw = dynamic_cast<BlackAndWhiteFigure*>(p);
			assert(bw);

			if (isBlackBrhush)
				bw->SetBlack();
			else
				bw->SetWhite();			
		}

	private:
		BlackAndWhiteFigure* CreateNewFigure(EnumFigure figure_type) const override
		{
			return new BlackAndWhiteFigure(figure_type, isBlackBrhush);
		}

		bool isBlackBrhush = true;
	};
}
