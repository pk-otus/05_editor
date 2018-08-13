#pragma once
#include "Color.h"

namespace GraphicEditor
{
	class IGraphicPrimitive;

	class IGraphicPrimitiveCreator //abstract factory
	{
	public:
		virtual ~IGraphicPrimitiveCreator() = default;

		virtual bool						TrySetBrushColor(color_type col) = 0;

		virtual const IGraphicPrimitive*	CreateTriangle()	const = 0;
		virtual const IGraphicPrimitive*	CreateCircle()		const = 0;

		virtual void						DeletePrimitive(const IGraphicPrimitive* p) const = 0;

	};
}
