#pragma once
#include <iostream>
#include "../GraphicEditor.h"

namespace GraphicEditor
{
	class DatabaseDocumentEditor : public IDocumentEditor
	{
	public:
		DatabaseDocumentEditor(const std::string& url, uint32_t p) : 
			database_connect_url(url),
			database_connect_port(p) {}

		void CreateNewDocument(const std::string& file_name) override
		{
			EstablishConnection();
			std::cout << "\nCreating " << file_name;
			CloseConnection();
		}
		void ImportFromFile(const std::string& file_name) override
		{
			EstablishConnection();
			std::cout << "\nImporting " << file_name;
			CloseConnection();
		}
		void ExportToFile(const std::string& file_name) override
		{
			EstablishConnection();
			std::cout << "\nExporting " << file_name;
			CloseConnection();
		}
	private:
		void EstablishConnection() const
		{
			std::cout << "\nConnecting to " 
				<< database_connect_url + ':' + std::to_string(database_connect_port);
		}
		void CloseConnection() const
		{
			std::cout << "\nClose connection "
				<< database_connect_url + ':' + std::to_string(database_connect_port) << '\n';
		}
		const std::string database_connect_url;
		const uint32_t database_connect_port;
	};
}
