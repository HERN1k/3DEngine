cmake_minimum_required(VERSION 3.27.1 FATAL_ERROR)

#set(EDITOR_PROJECT_NAME 3DEngineEditor)
project(3DEngineEditor)

add_executable(3DEngineEditor
	src/main.cpp
)

target_link_libraries(3DEngineEditor 3DEngineCore)
target_compile_features(3DEngineEditor PUBLIC cxx_std_17)

set_target_properties(3DEngineEditor PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)