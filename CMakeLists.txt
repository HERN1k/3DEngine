cmake_minimum_required(VERSION 3.27.1 FATAL_ERROR)

set(PROJECT_NAME 3DEngine)
#project(3DEngine)

add_subdirectory(3DEngineCore)
add_subdirectory(3DEngineEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT 3DEngineEditor)