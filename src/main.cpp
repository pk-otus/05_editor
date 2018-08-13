#include "../include/EditorCore.h"
#include "../include/IGraphicPrimitive.h"

int main(int, char *[])
{
	using namespace GraphicEditor;

	DocumentEditors		editor_type = DocumentEditors::UseLocalFileDocumentEditor;

//#define USE_BLACKANDWHITE 1

#ifdef USE_BLACKANDWHITE
	PrimitiveCreators	creator_type = PrimitiveCreators::UseBlackWhitePrimitiveCreator;
#else
	PrimitiveCreators	creator_type = PrimitiveCreators::UseRGBPrimitiveCreator;
#endif

	{
		EditorCore editor(editor_type, creator_type);

		editor.FileMenu()->CreateNewDocument("test.bmp");

		editor.EditMenu()->TrySetBrushColor(COLOR_RED);
		auto triangle1 = editor.EditMenu()->CreateTriangle();

		editor.EditMenu()->TrySetBrushColor(COLOR_WHITE); 
		auto circle1 = editor.EditMenu()->CreateCircle();

		triangle1->Draw();
		circle1->Draw();

		editor.EditMenu()->DeletePrimitive(triangle1);
		editor.EditMenu()->DeletePrimitive(circle1);

		editor.FileMenu()->ExportToFile("exported_test.bmp");
	}

	return 0;
}
