cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# project name and enable C++ support
project(lcptdipole CXX C)


# Git module
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)
git_describe(GIT_DESCRIBE)
git_local_changes(GIT_LOCAL_CHANGES)

#if (APPLE)
#	SET(MACOSX_DEPLOYMENT_TARGET ${DARWIN_MAJOR_SDK_VERSION}.${DARWIN_MINOR_SDK_VERSION})
#	SET(CMAKE_CXX_FLAGS "--sysroot ${CMAKE_OSX_SYSROOT} ${CMAKE_CXX_FLAGS}")
#	MESSAGE("Setting MACOSX_DEPLOYMENT_TARGET to '${MACOSX_DEPLOYMENT_TARGET}'.")
#endif()

# Optimization on (for debug flags, change to Debug)
set(CMAKE_BUILD_TYPE Release)


find_package(GSL REQUIRED)
include_directories(${GSL_INCLUDE_DIRS})


include_directories("./dipole/")
add_subdirectory(src)
add_subdirectory(dipole)


set_target_properties(example PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_target_properties(lcptdipole PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
	LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
)
