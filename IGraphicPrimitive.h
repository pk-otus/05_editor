#pragma once
namespace GraphicEditor
{
	class IGraphicPrimitive
	{
	public:
		virtual ~IGraphicPrimitive() = default;

		virtual void Draw() const = 0;
	};
}