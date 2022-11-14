configure_file("${CMAKE_CURRENT_SOURCE_DIR}/gitsha1.cpp.in" "${CMAKE_CURRENT_BINARY_DIR}/gitsha1.cpp" @ONLY)

add_library(
	lcptdipole
	STATIC
	dipoleamplitude.cpp
	interpolation2d.cpp
)

