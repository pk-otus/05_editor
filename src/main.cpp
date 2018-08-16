#include "../include/GraphicEditor.h"

int main(int, char *[])
{
	using namespace GraphicEditor;

	DocumentEditors		editor_type = DocumentEditors::UseDatabaseDocumentEditor;

//#define USE_BLACKANDWHITE 1

#ifdef USE_BLACKANDWHITE
	PrimitiveCreators	creator_type = PrimitiveCreators::UseBlackWhitePrimitiveCreator;
#else
	PrimitiveCreators	creator_type = PrimitiveCreators::UseRGBPrimitiveCreator;
#endif

	{
		auto editor = ICoreEditor::CreateEditor(editor_type, creator_type);

		editor->FileMenu()->CreateNewDocument("test.bmp");

		editor->EditMenu()->TrySetBrushColor(COLOR_RED);
		auto figure1 = editor->EditMenu()->CreatePrimitive(EnumFigure::Hexagon);

		editor->EditMenu()->TrySetBrushColor(COLOR_WHITE);
		auto figure2 = editor->EditMenu()->CreatePrimitive(EnumFigure::Circle);

		figure1->Draw();
		editor->EditMenu()->TrySetBrushColor(COLOR_BLACK);
		editor->EditMenu()->ChangeFillColor(figure1);

		figure1->Draw();
		figure2->Draw();

		editor->EditMenu()->TransformCirclesToSquares();

		figure1->Draw();
		figure2->Draw();

		editor->EditMenu()->DeletePrimitive(figure1);
		editor->EditMenu()->DeletePrimitive(figure2);

		editor->FileMenu()->ExportToFile("exported_test.bmp");
	}

	return 0;
}
