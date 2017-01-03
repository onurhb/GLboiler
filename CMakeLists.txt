#------------------------------------------------------------------------------
#░░▄░░░▄░▄▄▄▄░░░░░░░░░░░░░░░
#░░█▀▄▀█░█▄▄░░░░░░░░░░░░░░░░
#░░█░░░█░█▄▄▄░░░░░░░░░░░░░░░
#░░░░░░░░░░░░░░░░░░░░░░░░░░░
#░▄▄▄░▄░░░▄░░▄▄▄░▄▄▄▄▄░░▄▄▄░
#█░░░░█░░░█░█░░░░░░█░░░█░░░█
#█░▀█░█░░░█░░▀▀▄░░░█░░░█▀▀▀█
#░▀▀▀░░▀▀▀░░▄▄▄▀░░░▀░░░▀░░░▀
#------------------------------------------------------------------------------
project(Project)
cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")
#------------------------------------------------------------------------------
#Path to CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)
#Path to dependencies
set(DEPENDENCIES_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies)
#Path to glfw library
set(GLFW_LOCATION ${DEPENDENCIES_LOCATION}/glfw)

#------------------------------------------------------------------------------
include_directories(
        ${DEPENDENCIES_LOCATION}/glad/include
        ${DEPENDENCIES_LOCATION}/glm/glm
        ${DEPENDENCIES_LOCATION}/curl/include
        ${DEPENDENCIES_LOCATION}/nanovg/include
)

#------------------------------------------------------------------------------
set(GLAD_SOURCE_FILES
        ${DEPENDENCIES_LOCATION}/glad/src/glad.c)

set(NANOVG_SOURCE_FILES
        ${DEPENDENCIES_LOCATION}/nanovg/nanovg.c)

set(NATIVEFILEDIALOGS_SOURCE_FILES
        ${DEPENDENCIES_LOCATION}/nativefiledialogs/nfd_win.cpp
        ${DEPENDENCIES_LOCATION}/nativefiledialogs/nfd_common.c)

set(SOURCE_FILES
        Source/main.cpp
        Source/Utils/Thread.h
        Source/Graphics/Texture.h
        Source/Utils/FileDialog.h
        Source/Utils/HTTP.cpp Source/Utils/HTTP.h
        Source/Application.cpp Source/Application.h
        Source/Graphics/Shader.cpp Source/Graphics/Shader.h
        Source/Graphics/Window.cpp Source/Graphics/Window.h
        Source/Graphics/UserInterface.cpp Source/Graphics/UserInterface.h
        )
#------------------------------------------------------------------------------
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${NANOVG_SOURCE_FILES} ${GLAD_SOURCE_FILES} ${NATIVEFILEDIALOGS_SOURCE_FILES})
#------------------------------------------------------------------------------
find_package(OpenGL REQUIRED)
find_package(GLFW REQUIRED glfw3)
#------------------------------------------------------------------------------
if (OPENGL_FOUND)
    target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES})
    message("-- OPENGL library was found")
endif (OPENGL_FOUND)


if (GLFW_FOUND)
    include_directories(${GLFW_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${GLFW_LIBRARIES})
    message("-- GLFW library was found")
endif ()



