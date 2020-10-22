cmake_minimum_required(VERSION 3.5)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

project(sdlsnake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(raylib_VERBOSE   ON)

#set(raylib_USE_STATIC_LIBS ON)


add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

#include_directories(${entt_SOURCE_DIR}/src)
find_package(raylib CONFIG REQUIRED)

#find_package(raylib 2.5.0 REQUIRED) # Requires at least version 2.5.0

find_package(EnTT CONFIG REQUIRED)

find_package(unofficial-box2d CONFIG REQUIRED)


find_package(glfw3 REQUIRED)
find_package(GLEW)


#set(BOOST_ASIO_DISABLE_NOEXCEPT ON)
#find_package(Boost COMPONENTS system program_options thread fiber unit_test_framework log REQUIRED)
#find_package(Threads REQUIRED)

set(components 
    components/tags.h
    components/transform.h
    components/transform.cpp
    components/sprite.cpp
    components/sprite.h
    
    )
set(systems    
    box2d/box2draylibdraw.h
    box2d/box2draylibdraw.cpp
    sys/system.cpp
    sys/system.h
    sys/eventsystem.h
    sys/eventsystem.cpp
    sys/collisionsystem.cpp
    sys/collisionsystem.h
    sys/playercontrolsystem.cpp
    sys/playercontrolsystem.h
    sys/rendersystem.cpp
    sys/rendersystem.h
    sys/raylibrendersystem.h
    sys/raylibrendersystem.cpp)

set(sdlsnake_SRC 
    game.cpp 
    game.h
    ${components}
    ${systems})

set(sdlsnake_libs 
    EnTT::EnTT 
#     Threads::Threads 
#     ${Boost_LIBRARIES}  
     glfw
#     GL
#     GLEW::GLEW
     unofficial::box2d::box2d   
     ${raylib_LIBRARIES} )
 
#set(CMAKE_CXX_LINK_LIBRARY_FLAG ${raylib_LDFLAGS})


add_executable(sdlsnake main.cpp ${sdlsnake_SRC})

target_include_directories(sdlsnake PRIVATE ${raylib_INCLUDE_DIRS})

target_link_libraries(sdlsnake PRIVATE ${sdlsnake_libs})