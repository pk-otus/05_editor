#include <gtest/gtest.h>

#include "../include/DataBaseEditor/DataBaseEditor.h"
#include "../include/LocalEditor/LocalDocumentEditor.h"

using namespace GraphicEditor;

TEST(GraphEditorTest, NewDocument)
{
	auto loc = new LocalFileDocumentEditor("c:\\work\\");
	auto db = new DatabaseDocumentEditor("127.0.0.1", 7777);

	testing::internal::CaptureStdout();
	loc->CreateNewDocument("test.bmp");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_NE(std::string::npos, output.find("c:\\work\\test.bmp"));

	testing::internal::CaptureStdout();
	db->CreateNewDocument("test.bmp");
	output = testing::internal::GetCapturedStdout();
	ASSERT_NE(std::string::npos, output.find("127.0.0.1:7777"));
	ASSERT_NE(std::string::npos, output.find("Creating remote test.bmp"));

	delete loc;
	delete db;
}
