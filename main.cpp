#include <string>
#include <cassert>
#include <iostream>
#include <stdexcept>

namespace
{
	using color_type = uint64_t;

	enum EnumColors : color_type
	{
		COLOR_BLACK		= 0x000000,
		COLOR_RED		= 0xFF0000,
		COLOR_GREEN		= 0x00FF00,
		COLOR_BLUE		= 0x0000FF,
		COLOR_WHITE		= 0xFFFFFF
	};

	std::string BWColorName(bool black) { return black ? "black" : "white"; }
}

class IGraphicPrimitive
{
public:
	virtual ~IGraphicPrimitive() = default;

	virtual void Draw() const = 0;
};

class IGraphicPrimitiveCreator //abstract factory
{
public:
	virtual ~IGraphicPrimitiveCreator() = default;

	virtual bool						TrySetBrushColor(color_type col) = 0;

	virtual const IGraphicPrimitive*	CreateTriangle()	const = 0;
	virtual const IGraphicPrimitive*	CreateCircle()		const = 0;

	virtual void						DeletePrimitive(const IGraphicPrimitive* p) const = 0;

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
	RGBFigure(color_type col) : color(col) {}

	color_type GetColor() const { return color; }
private:
	color_type color;
};

class TriangleRGB : RGBFigure, public IGraphicPrimitive
{
public:
	TriangleRGB(color_type col) : RGBFigure(col) {}
	void Draw() const override { std::cout << "I am RGB triangle, my color is " << std::hex << GetColor() << '\n'; }
};

class CircleRGB : RGBFigure, public IGraphicPrimitive
{
public:
	CircleRGB(color_type col) : RGBFigure(col) {}
	void Draw() const override { std::cout << "I am RGB circle, my color is " << std::hex << GetColor() << '\n'; }
};

class TriangleBW : public IGraphicPrimitive, BlackAndWhiteFigure
{
public:
	TriangleBW(bool bw) : BlackAndWhiteFigure(bw) {}
	void Draw() const override { std::cout	<< "I am Black/White triangle, my color is "
										<< BWColorName(IsBlack()) << '\n'; }
};

class CircleBW : public IGraphicPrimitive, BlackAndWhiteFigure
{
public:
	CircleBW(bool bw) : BlackAndWhiteFigure(bw) {}
	void Draw() const override { std::cout	<< "I am Black/White circle, my color is "
										<< BWColorName(IsBlack()) << '\n'; }
};

class BlackWhiteGraphicPrimitiveCreator : public IGraphicPrimitiveCreator
{
public:
	const IGraphicPrimitive* CreateTriangle() const override
	{
		return new TriangleBW(isBlackBrhush);
	}
	const IGraphicPrimitive* CreateCircle() const override
	{
		return new CircleBW(isBlackBrhush);
	}
	void DeletePrimitive(const IGraphicPrimitive* p) const override
	{
		delete p;
	}

	bool TrySetBrushColor(color_type col) override
	{
		switch(col)
		{
		case COLOR_BLACK:
			isBlackBrhush = true;
			break;
		case COLOR_WHITE:
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
	const IGraphicPrimitive * CreateTriangle() const override
	{
		return new TriangleRGB(brush_color);
	}
	const IGraphicPrimitive* CreateCircle() const override
	{
		return new CircleRGB(brush_color);
	}
	void DeletePrimitive(const IGraphicPrimitive* p) const override
	{
		delete p;
	}

	bool TrySetBrushColor(color_type col) override
	{
		brush_color = col;
		return true; //success
	}
private:
	color_type brush_color = 0x00000;
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
	LocalFileDocumentEditor(const std::string& workdir) : working_directory(workdir) {}

	void CreateNewDocument(const std::string& file_name) override
	{
		std::cout << "Create new " << FullName(file_name) << '\n';
	}
	void ImportFromFile(const std::string& file_name) override
	{
		std::cout << "Import from " << FullName(file_name) << '\n';
	}
	void ExportToFile(const std::string& file_name) override
	{
		std::cout << "Export to " << FullName(file_name) << '\n';
	}
private:
	std::string FullName(const std::string& file_name) const
	{
		return working_directory + file_name;
	}

	const std::string working_directory;
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
		doc_editor			(InitializeDocumentEditor(cfg_editor)),
		primitive_creator	(InitializeFigureCreator(cfg_creator))
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
			throw std::logic_error("unsupported figure creator");
		}
	}

	static IDocumentEditor* InitializeDocumentEditor(DocumentEditors cfg_editor)
	{
		switch (cfg_editor)
		{
		case DocumentEditors::UseLocalFileDocumentEditor:
			return new LocalFileDocumentEditor("c:\\work\\");
		default:
			throw std::logic_error("unsupported file editor");
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

	getchar();

	return 0;
}