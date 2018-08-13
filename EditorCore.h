#pragma once
#include "IDocumentEditor.h"
#include "IGraphicPrimitiveCreator.h"

namespace GraphicEditor
{	
	enum class PrimitiveCreators
	{
		UseBlackWhitePrimitiveCreator,
		UseRGBPrimitiveCreator
	};

	enum class DocumentEditors
	{
		UseLocalFileDocumentEditor
	};

	class EditorCore
	{
	public:
		EditorCore(DocumentEditors cfg_editor, PrimitiveCreators cfg_creator);

		IDocumentEditor*			FileMenu() const { return doc_editor; }
		IGraphicPrimitiveCreator*	EditMenu() const { return primitive_creator; }


	private:
		IDocumentEditor*				const doc_editor;
		IGraphicPrimitiveCreator*		const primitive_creator;
	};
}
