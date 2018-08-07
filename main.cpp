#include <string>
#include <cassert>
#include <iostream>

class IGraphicPrimitive
{
public:
	virtual ~IGraphicPrimitive() = default;

	virtual void Draw() = 0;
};

class IGraphicPrimitiveCreator
{
public:
	virtual ~IGraphicPrimitiveCreator() = default;

	virtual bool				SetBrushColor(uint64_t color) = 0;

	virtual IGraphicPrimitive*	CreateTriangle()	const = 0;
	virtual IGraphicPrimitive*	CreateCircle()		const = 0;
	virtual void				DeletePrimitive(IGraphicPrimitive* p) const = 0;

};

class BlackAndWhiteFigure
{
public:
	BlackAndWhiteFigure(bool black) : isBlack(black) {}

	bool IsBlack() const { return isBlack; }
private:
	bool isBlack;
};
class RGBFigure
{
public:
	RGBFigure(uint64_t col) : color(col) {}

	uint64_t GetColor() const { return color; }
private:
	uint64_t color;
};

class TriangleRGB : RGBFigure, public IGraphicPrimitive
{
public:
	TriangleRGB(uint64_t col) : RGBFigure(col) {}		
	void Draw() override { std::cout << "I am RGB triangle, my color is " << std::hex << GetColor() << '\n'; }
};

class CircleRGB : RGBFigure, public IGraphicPrimitive
{
public:
	CircleRGB(uint64_t col) : RGBFigure(col) {}
	void Draw() override { std::cout << "I am RGB circle, my color is " << std::hex << GetColor() << '\n'; }
};

class TriangleBW : public IGraphicPrimitive, BlackAndWhiteFigure
{
public:
	TriangleBW(bool bw) : BlackAndWhiteFigure(bw) {}
	void Draw() override { std::cout	<< "I am Black/White triangle, my color is " 
										<< (IsBlack() ? "black" : "white") << '\n'; }
};

class CircleBW : public IGraphicPrimitive, BlackAndWhiteFigure
{
public:
	CircleBW(bool bw) : BlackAndWhiteFigure(bw) {}
	void Draw() override { std::cout	<< "I am Black/White circle, my color is " 
										<< (IsBlack() ? "black" : "white") << '\n'; }
};

class BlackWhiteGraphicPrimitiveCreator : public IGraphicPrimitiveCreator
{
public:
	IGraphicPrimitive* CreateTriangle() const override
	{
		return new TriangleBW(isBlackBrhush);
	}
	IGraphicPrimitive* CreateCircle() const override
	{
		return new CircleBW(isBlackBrhush);
	}
	void DeletePrimitive(IGraphicPrimitive* p) const override
	{
		delete p;
	}

	bool SetBrushColor(uint64_t color) override
	{
		switch(color)
		{
		case 0:
			isBlackBrhush = true;
			break;
		case 0xFFFFFF:
			isBlackBrhush = false;
			break;
		default:
			return false; //not changed
		}
		return true; //changed
	}
private:
	bool isBlackBrhush = true;
};

class RGBGraphicPrimitiveCreator : public IGraphicPrimitiveCreator
{
public:
	IGraphicPrimitive * CreateTriangle() const override
	{
		return new TriangleRGB(brush_color);
	}
	IGraphicPrimitive* CreateCircle() const override
	{
		return new CircleRGB(brush_color);
	}
	void DeletePrimitive(IGraphicPrimitive* p) const override
	{
		delete p;
	}

	bool SetBrushColor(uint64_t color) override
	{
		brush_color = color;
		return true; //success
	}
private:
	uint64_t brush_color = 0;
};

class IDocumentEditor
{
public:
	virtual ~IDocumentEditor() = default;

	virtual void				CreateNewDocument(const std::string& file_name) = 0;
	virtual void				ImportFromFile(const std::string& file_name) = 0;
	virtual void				ExportToFile(const std::string& file_name) = 0;
};

class LocalFileDocumentEditor : public IDocumentEditor
{
public:
	void CreateNewDocument(const std::string& file_name) override
	{
		std::cout << "Create new c:/" << file_name << '\n';
	}
	void ImportFromFile(const std::string& file_name) override
	{
		std::cout << "Import from c:/" << file_name << '\n';
	}
	void ExportToFile(const std::string& file_name) override
	{
		std::cout << "Export to c:/" << file_name << '\n';
	}
};

enum class PrimitiveCreators
{
	UseBlackWhitePrimitiveCreator,
	UseRGBPrimitiveCreator
};

enum class DocumentEditors
{
	UseLocalFileDocumentEditor
};

class GraphicEditor 
{
public:
	GraphicEditor(DocumentEditors cfg_editor, PrimitiveCreators cfg_creator) :
		doc_editor(InitializeDocumentEditor(cfg_editor)),
		primitive_creator(InitializeFigureCreator(cfg_creator))
	{}

	IDocumentEditor*			FileMenu() const { return doc_editor; }
	IGraphicPrimitiveCreator*	EditMenu() const { return primitive_creator; }


private:
	static IGraphicPrimitiveCreator* InitializeFigureCreator(PrimitiveCreators cfg_creator)
	{
		switch (cfg_creator)
		{
		case PrimitiveCreators::UseBlackWhitePrimitiveCreator:
			return new BlackWhiteGraphicPrimitiveCreator();
		case PrimitiveCreators::UseRGBPrimitiveCreator:
			return new RGBGraphicPrimitiveCreator();
		default:
			throw std::logic_error("unsupported creator");
		}
	}

	static IDocumentEditor* InitializeDocumentEditor(DocumentEditors cfg_editor)
	{
		switch (cfg_editor)
		{
		case DocumentEditors::UseLocalFileDocumentEditor:
			return new LocalFileDocumentEditor();
		default:
			throw std::logic_error("unsupported creator");
		}
	}

	IDocumentEditor*				const doc_editor;
	IGraphicPrimitiveCreator*		const primitive_creator;
};


int main(int, char *[])
{
	DocumentEditors		editor_type = DocumentEditors::UseLocalFileDocumentEditor;

//#define USE_BLACKANDWHITE 1

#ifdef USE_BLACKANDWHITE
	PrimitiveCreators	creator_type = PrimitiveCreators::UseBlackWhitePrimitiveCreator;
#else
	PrimitiveCreators	creator_type = PrimitiveCreators::UseRGBPrimitiveCreator;
#endif

	{
		GraphicEditor editor(editor_type, creator_type);

		editor.FileMenu()->CreateNewDocument("test.bmp");

		editor.EditMenu()->SetBrushColor(0xFF0000);
		auto triangle1 = editor.EditMenu()->CreateTriangle();

		editor.EditMenu()->SetBrushColor(0xFFFFFF);
		auto circle1 = editor.EditMenu()->CreateCircle();

		triangle1->Draw();
		circle1->Draw();

		editor.EditMenu()->DeletePrimitive(triangle1);
		editor.EditMenu()->DeletePrimitive(circle1);

		editor.FileMenu()->ExportToFile("exported_test.bmp");
	}

	getchar();

	return 0;
}