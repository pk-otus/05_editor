#include <gtest/gtest.h>

#include "../include/DataBaseEditor/DataBaseEditor.h"
#include "../include/LocalEditor/LocalDocumentEditor.h"

using namespace GraphicEditor;

TEST(GraphEditorTest, StorageTest)
{
	testing::internal::CaptureStdout();
	auto loc = new LocalFileDocumentEditor("c:\\work\\");
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_NE(std::string::npos, output.find("c:\\work\\"));

	testing::internal::CaptureStdout();
	auto db = new DatabaseDocumentEditor("127.0.0.1", 7777);
	output = testing::internal::GetCapturedStdout();
	ASSERT_NE(std::string::npos, output.find("127.0.0.1:7777"));

	delete loc;
	delete db;
}
