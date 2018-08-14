#include <gtest/gtest.h>

#include "..//include/RGB/RGBFigure.h"
#include "..//include/BW/BlackAndWhiteFigure.h"

using namespace GraphicEditor;

TEST(GraphEditorTest, DisplayGraphicPrimitiveTest)
{
	auto circle_rgb = new RGBFigure(EnumFigure::Circle, COLOR_RED);
	testing::internal::CaptureStdout();	
	circle_rgb->Draw();
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_NE(std::string::npos, output.find("ff0000"));
	ASSERT_NE(std::string::npos, output.find("[PointCenter, Radius]"));

	auto square_bw = new BlackAndWhiteFigure(EnumFigure::Square, true);
	testing::internal::CaptureStdout();
	square_bw->Draw();
	output = testing::internal::GetCapturedStdout();

	ASSERT_NE(std::string::npos, output.find("[PointUpperLeft, SideLength]"));
	ASSERT_NE(std::string::npos, output.find("black"));

	delete circle_rgb;

}