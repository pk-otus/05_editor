cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
   project(editor VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
   project(editor VERSION 0.0.1)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE GRAPHEDITOR_INCLUDE include/*.h)
file(GLOB_RECURSE GRAPHEDITOR_SRC src/*.cpp)

add_executable(editor ${GRAPHEDITOR_HEADERS} ${GRAPHEDITOR_SRC})

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set_target_properties(editor PROPERTIES
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra
	)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set_target_properties(editor PROPERTIES
		COMPILE_OPTIONS -W3 
	)
endif()

install(TARGETS editor RUNTIME DESTINATION bin)

enable_testing()
add_subdirectory(test)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT a@a.a)

include (CPack)


