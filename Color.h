#pragma once 
#include <cstdint>

namespace GraphicEditor
{
	using color_type = uint64_t;

	enum EnumColors : color_type
	{
		COLOR_BLACK = 0x000000,
		COLOR_RED = 0xFF0000,
		COLOR_GREEN = 0x00FF00,
		COLOR_BLUE = 0x0000FF,
		COLOR_WHITE = 0xFFFFFF
	};
}
