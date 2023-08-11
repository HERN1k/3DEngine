cmake_minimum_required(VERSION 3.27.1 FATAL_ERROR)

set(ENGINE_PROJECT_NAME 3DEngineCore)
#project(3DEngineCore)

set(ENGINE_PUBLIC_INCLUDES
	includes/3DengineCore/Application.hpp
	includes/3DengineCore/Log.hpp
	includes/3DengineCore/Event.hpp
)

set(ENGINE_PRIVATE_INCLUDES
	src/3DengineCore/Window.hpp
)

set(ENGINE_PRIVATE_SOURCES
	src/3DengineCore/Application.cpp
	src/3DengineCore/Window.cpp
)

add_library(${ENGINE_PROJECT_NAME} STATIC 
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE src)
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory (../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)

add_subdirectory (../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE spdlog)

add_subdirectory (../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glad)