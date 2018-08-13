#pragma once
#include <string>

namespace GraphicEditor
{
	class IDocumentEditor
	{
	public:
		virtual ~IDocumentEditor() = default;

		virtual void	CreateNewDocument	(const std::string& file_name) = 0;
		virtual void	ImportFromFile		(const std::string& file_name) = 0;
		virtual void	ExportToFile		(const std::string& file_name) = 0;
	};
}
