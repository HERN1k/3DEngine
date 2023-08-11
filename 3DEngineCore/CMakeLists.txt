cmake_minimum_required(VERSION 3.27.1 FATAL_ERROR)

#set(ENGINE_PROJECT_NAME 3DEngineCore)
project(3DEngineCore)

add_library(3DEngineCore STATIC 
	src/3DEngineCore/Utils/test.cpp
	includes/3DengineCore/Utils/test.hpp
)

target_include_directories(3DEngineCore PUBLIC includes)
target_compile_features(3DEngineCore PUBLIC cxx_std_17)