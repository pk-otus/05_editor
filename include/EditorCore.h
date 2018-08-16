#pragma once
#include "GraphicEditor.h"

namespace GraphicEditor
{	
	class EditorCore : public ICoreEditor
	{
	public:
		EditorCore(DocumentEditors cfg_editor, PrimitiveCreators cfg_creator);

		IDocumentEditor*			FileMenu() const override { return doc_editor; }
		IGraphicPrimitiveCreator*	EditMenu() const override { return primitive_creator; }


	private:
		IDocumentEditor*				const doc_editor;
		IGraphicPrimitiveCreator*		const primitive_creator;
	};
}
