#pragma once
namespace GraphicEditor
{
	class BlackAndWhiteFigure
	{
	public:
		BlackAndWhiteFigure(bool black) : isBlack(black) {}

		bool IsBlack() const { return isBlack; }
	private:
		bool isBlack;
	};
}