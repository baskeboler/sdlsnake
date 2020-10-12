cmake_minimum_required(VERSION 3.5)

project(sdlsnake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



Include(FetchContent)

set(FETCHCONTENT_QUIET OFF)


FetchContent_Declare(
  entt
  GIT_REPOSITORY https://github.com/skypjack/entt
  GIT_TAG        v3.5.2)

FetchContent_MakeAvailable(entt)
include_directories(${entt_SOURCE_DIR}/src)

set(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)
# disable building entt tests
set(BUILD_TESTING OFF)

find_package(SDL2 REQUIRED)
#find_package(SDL_image REQUIRED)
#find_package(SDL_sound REQUIRED)
#find_package(SDL_GFX REQUIRED)

set(BOOST_ASIO_DISABLE_NOEXCEPT ON)
find_package(Boost COMPONENTS system program_options thread fiber unit_test_framework log REQUIRED)
find_package(Threads REQUIRED)

set(components 
    components/tags.h
    components/transform.h
    components/transform.cpp
    components/sprite.cpp
    components/sprite.h
    
    )
set(systems    
    sys/playercontrolsystem.cpp
    sys/playercontrolsystem.h
    sys/rendersystem.cpp
    sys/rendersystem.h)

set(sdlsnake_SRC 
    game.cpp 
    game.h
    ${components}
    ${systems})

set(sdlsnake_libs 
    SDL2::SDL2 SDL2_image SDL_sound SDL2_gfx EnTT::EnTT
     Threads::Threads ${Boost_LIBRARIES}     )
add_executable(sdlsnake main.cpp ${sdlsnake_SRC})
target_link_libraries(sdlsnake ${sdlsnake_libs})