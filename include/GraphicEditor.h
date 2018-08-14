#pragma once
#include <string>
#include <memory>

namespace GraphicEditor
{
	using color_type = uint64_t;

	enum class PrimitiveCreators
	{
		UseBlackWhitePrimitiveCreator,
		UseRGBPrimitiveCreator
	};

	enum class DocumentEditors
	{
		UseLocalFileDocumentEditor,
		UseDatabaseDocumentEditor
	};

	enum EnumColors : color_type
	{
		COLOR_BLACK = 0x000000,
		COLOR_RED = 0xFF0000,
		COLOR_GREEN = 0x00FF00,
		COLOR_BLUE = 0x0000FF,
		COLOR_WHITE = 0xFFFFFF
	};

	enum class EnumFigure
	{
		Triangle,
		Square,
		Hexagon,
		Circle
	};

	class AbstractFigure
	{
	public:
		virtual ~AbstractFigure() = default;
		virtual std::string  GetCoordinates() const = 0;
	};

	class IGraphicPrimitive
	{
	public:
		virtual ~IGraphicPrimitive() = default;

		virtual void Draw() const = 0;
	};

	class IGraphicPrimitiveCreator
	{
	public:
		virtual ~IGraphicPrimitiveCreator() = default;

		virtual IGraphicPrimitive*	CreatePrimitive(EnumFigure figure_type) = 0;
		virtual void	DeletePrimitive(IGraphicPrimitive* p) = 0;

		virtual bool	TrySetBrushColor(color_type col) = 0;
		virtual void	ChangeFillColor(IGraphicPrimitive* p) = 0;

		virtual void	TransformCirclesToSquares() = 0;
	};

	class IDocumentEditor
	{
	public:
		virtual ~IDocumentEditor() = default;

		virtual void	CreateNewDocument(const std::string& file_name) = 0;
		virtual void	ImportFromFile(const std::string& file_name) = 0;
		virtual void	ExportToFile(const std::string& file_name) = 0;
	};

	class ICoreEditor
	{
	public:
		static std::unique_ptr<ICoreEditor> 
						CreateEditor(DocumentEditors cfg_editor, PrimitiveCreators cfg_creator);

		virtual ~ICoreEditor() = default;
		virtual IDocumentEditor*			FileMenu() const = 0;
		virtual IGraphicPrimitiveCreator*	EditMenu() const = 0;
	};
}
