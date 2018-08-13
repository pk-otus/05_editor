#pragma  once
#include "../IGraphicPrimitiveCreator.h"
#include "ConcreteFiguresBW.h"
#include <cassert>

namespace GraphicEditor
{
	class BlackWhiteGraphicPrimitiveCreator : public IGraphicPrimitiveCreator
	{
	public:
		IGraphicPrimitive* CreateTriangle() const override
		{
			return new TriangleBW(isBlackBrhush);
		}
		IGraphicPrimitive* CreateCircle() const override
		{
			return new CircleBW(isBlackBrhush);
		}
		IGraphicPrimitive* CreateSquare() const override
		{
			return new SquareBW(isBlackBrhush);
		}
		IGraphicPrimitive* CreateHexagon() const override
		{
			return new HexagonBW(isBlackBrhush);
		}

		void DeletePrimitive(const IGraphicPrimitive* p) const override
		{
			delete p;
		}

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
		void ChangeFillColor(IGraphicPrimitive* p) const override
		{
			auto bw = dynamic_cast<BlackAndWhiteFigure*>(p);
			assert(bw);

			if (isBlackBrhush)
				bw->SetBlack();
			else
				bw->SetWhite();			
		}
	private:
		bool isBlackBrhush = true;
	};
}
