#pragma once
#include "../IGraphicPrimitive.h"

namespace GraphicEditor
{
	class BlackAndWhiteFigure : public IGraphicPrimitive
	{
	public:
		BlackAndWhiteFigure(bool black) : isBlack(black) {}

		bool IsBlack() const { return isBlack; }

		void SetWhite() { isBlack = false; }
		void SetBlack() { isBlack = true; }

	private:
		bool isBlack;
	};
}