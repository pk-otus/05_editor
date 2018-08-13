#include "EditorCore.h"

#include <stdexcept>

#include "BW/BlackWhitePrimitiveCreator.h"
#include "RGB/RGBPrimitiveCreator.h"
#include "LocalEditor/LocalDocumentEditor.h"

using namespace GraphicEditor;

namespace
{
	IGraphicPrimitiveCreator* InitializeFigureCreator(PrimitiveCreators cfg_creator)
	{
		switch (cfg_creator)
		{
		case PrimitiveCreators::UseBlackWhitePrimitiveCreator:
			return new BlackWhiteGraphicPrimitiveCreator();
		case PrimitiveCreators::UseRGBPrimitiveCreator:
			return new RGBGraphicPrimitiveCreator();
		default:
			throw std::logic_error("unsupported figure creator");
		}
	}

	IDocumentEditor* InitializeDocumentEditor(DocumentEditors cfg_editor)
	{
		switch (cfg_editor)
		{
		case DocumentEditors::UseLocalFileDocumentEditor:
			return new LocalFileDocumentEditor("c:\\work\\");
		default:
			throw std::logic_error("unsupported file editor");
		}
	}
}

EditorCore::EditorCore(DocumentEditors cfg_editor, PrimitiveCreators cfg_creator):
	doc_editor(InitializeDocumentEditor(cfg_editor)),
	primitive_creator(InitializeFigureCreator(cfg_creator))
{
}
