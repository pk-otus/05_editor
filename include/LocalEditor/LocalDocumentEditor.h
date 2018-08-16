#pragma once
#include <iostream>
#include "../GraphicEditor.h"

namespace GraphicEditor
{
	class LocalFileDocumentEditor : public IDocumentEditor
	{
	public:
		LocalFileDocumentEditor(const std::string& workdir) : working_directory(workdir)
		{
			std::cout << "Found working directory " << working_directory;
		}

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
}
