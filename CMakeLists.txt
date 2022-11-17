cmake_minimum_required(VERSION 3.10)

# set the project name
project(IndieStudio VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(WIN32)
    set( CMAKE_CXX_COMPILER "C:/MinGW/bin/" )
    set( CMAKE_C_COMPILER "C:/MinGW/bin/" )
endif(WIN32)


# add the executable
add_executable(IndieStudio
    Components/Bomb.cpp
    Components/Bomb.hpp
    Components/Camera.cpp
    Components/Camera.hpp
    Components/Collision.cpp
    Components/Collision.hpp
    Components/Health.hpp
    Components/IComponent.hpp
    Components/Movements.cpp
    Components/Movements.hpp
    Components/Object.cpp
    Components/Object.hpp
    Components/Render.cpp
    Components/Render.hpp
    Components/Shapes.cpp
    Components/Shapes.hpp
    Components/Text.cpp
    Components/Text.hpp
    Components/Ia.cpp

    Entity/Entity.cpp
    Entity/Entity.hpp

    System/Menu.cpp
    System/Menu.hpp
    System/System.hpp
    System/Draw.cpp
    System/Draw.hpp
    System/Time.hpp
    System/Time.cpp

    Builders/BoxBuilder.hpp
    Builders/CameraBuilder.cpp
    Builders/CameraBuilder.hpp
    Builders/Director.cpp
    Builders/Director.hpp
    Builders/IEntityBuilder.hpp
    Builders/MapBuilder.cpp
    Builders/MapBuilder.hpp
    Builders/PlayerBuilder.cpp
    Builders/PlayerBuilder.hpp
    Builders/SphereBuilder.hpp

    Encapsulation/Sphere.cpp
    Encapsulation/Sphere.hpp

    IndieStudio.cpp
    IndieStudio.hpp
    )

if (NOT raylib_FOUND)
    INCLUDE(FetchContent)

    FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        SET(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
        SET(raylib_FOUND TRUE)
    endif()
    TARGET_LINK_LIBRARIES(IndieStudio raylib)
endif()
