#pragma  once
#include "../IGraphicPrimitiveCreator.h"
#include "ConcreteFiguresBW.h"

namespace GraphicEditor
{
	class BlackWhiteGraphicPrimitiveCreator : public IGraphicPrimitiveCreator
	{
	public:
		const IGraphicPrimitive* CreateTriangle() const override
		{
			return new TriangleBW(isBlackBrhush);
		}
		const IGraphicPrimitive* CreateCircle() const override
		{
			return new CircleBW(isBlackBrhush);
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
	private:
		bool isBlackBrhush = true;
	};
}
