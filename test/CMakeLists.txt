cmake_minimum_required(VERSION 3.2)

project(test_grapheditor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

file(GLOB GRAPHEDITOR_TEST *.cpp)

add_executable(grapheditor_test_google ${GRAPHEDITOR_TEST} ../src/ConcreteFigures.cpp)

set_target_properties(grapheditor_test_google PROPERTIES
INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(grapheditor_test_google ${GTEST_LIBRARIES})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_link_libraries(grapheditor_test_google pthread)
endif()

add_test(StorageTest grapheditor_test_google)
add_test(DocumentImportExport grapheditor_test_google)
add_test(NewDocument grapheditor_test_google)
add_test(DisplayGraphicPrimitiveTest grapheditor_test_google)