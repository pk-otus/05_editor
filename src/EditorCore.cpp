#include <stdexcept>

#include "../include/EditorCore.h"
#include "../include/BW/BlackWhitePrimitiveCreator.h"
#include "../include/RGB/RGBPrimitiveCreator.h"
#include "../include/LocalEditor/LocalDocumentEditor.h"
#include "../include/DataBaseEditor/DataBaseEditor.h"

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
		case DocumentEditors::UseDatabaseDocumentEditor:
			return new DatabaseDocumentEditor("127.0.0.1", 7777);
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

std::unique_ptr<ICoreEditor> ICoreEditor::CreateEditor(	DocumentEditors cfg_editor, 
										PrimitiveCreators cfg_creator)
{
	return std::unique_ptr<ICoreEditor>(new EditorCore(cfg_editor, cfg_creator));
}
