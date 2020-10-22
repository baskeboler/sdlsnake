#include "game.h"

#include "sys/raylibrendersystem.h"
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

//#include <GL/glew.h>
//#include <GL/glu.h>
//#include <GLES3/gl3.h>
//#include <SDL.h>
//#include <SDL_opengl.h>

#include <box2d/box2d.h>

#include "components/all.h"

entt::registry &Game::registry() { return _registry; }

entt::entity Game::getPlayerEntity() const { return playerEntity; }

bool Game::getIsRunning() const { return isRunning; }

void Game::setIsRunning(bool value) { isRunning = value; }

entt::entity Game::createRandomEnemy() {
  auto ent = _registry.create();
  _registry.emplace<snake::Enemy>(ent);
  int w = 800, h = 600;
  //  SDL_GetRendererOutputSize(_renderer, &w, &h);
  int x = std::rand() % (w * 5);
  int y = std::rand() % (h * 5);
  std::cout << "creating enemy in (" << x << ", " << y << ")" << std::endl;
  _registry.emplace<snake::Transform>(ent, x, y);
  glm::u8vec4 color = {std::rand() % 256, std::rand() % 256, std::rand() % 256,
                       255};
  _registry.emplace<snake::Sprite>(ent, snake::RECT_FILLED, 50, 50, color);
  return ent;
}

entt::entity Game::createPlayer() {
  auto playerEntity = _registry.create();
  _registry.emplace<snake::Player>(playerEntity);
  _registry.emplace<snake::Transform>(playerEntity, 100, 100);
  glm::u8vec4 color = {0, 255, 0, 255};
  _registry.emplace<snake::Sprite>(playerEntity, snake::CIRCLE_FILLED, 100, 100,
                                   color);
  return playerEntity;
}

void Game::on_mousewheel_signal(int i) {
  std::cout << "mousewheel " << i << std::endl;
}

int Game::getWindowWidth() const { return _windowWidth; }

int Game::getWindowHeight() const { return _windowHeight; }

void Game::signalClose() { exit_signal.publish(); }

void Game::processInput() {}

Game::Game(bool r, const std::string &t, int ww, int wh)
    : isRunning{r}, _title{t}, _tick_count{0}, _windowWidth{ww},
      _windowHeight{wh}, exit_signal_sink{exit_signal} {}

Game::~Game() {}

bool Game::initialize() {

  exit_signal_sink.connect<&Game::on_exit_signal>(this);

  eventSystem = std::make_unique<EventSystem>(shared_from_this());
  renderSys = std::make_unique<RaylibRenderSystem>(shared_from_this());
  renderSys->init();
  playerControlSys = std::make_unique<PlayerControlSystem>(shared_from_this());
  playerEntity = createPlayer();

  //  auto handler = [](int i) { std::cout << "mousewheel " << i; };

  //  eventSystem->handleMouseWheel<&handler>(handler);

  eventSystem->signal_mousewheel_sink.connect<&Game::on_mousewheel_signal>(
      this);

  for (int i = 0; i < 115; i++) {
    createRandomEnemy();
  }
  return true;
}

// bool Game::initialize() {
//  int res = SDL_Init(SDL_INIT_EVERYTHING);
//  if (res != 0) {
//    SDL_Log("Unable to initilize SDL: %s", SDL_GetError());
//    return false;
//  }

//  _window =
//      SDL_CreateWindow(_title.c_str(), 100, 100, 1024, 768,
//      SDL_WINDOW_OPENGL);
//  if (!_window) {
//    SDL_Log("Failed to create window: %s", SDL_GetError());
//    return false;
//  }

//  _renderer = SDL_CreateRenderer(
//      _window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//  if (!_renderer) {
//    SDL_Log("Failed to create renderer: %s", SDL_GetError());
//    return false;
//  }

//  renderSys = std::make_unique<RenderSystem>(shared_from_this());
//  playerControlSys =
//  std::make_unique<PlayerControlSystem>(shared_from_this()); playerEntity =
//  createPlayer();

//  for (int i = 0; i < 15; i++) {
//    createRandomEnemy();
//  }
//  return true;
//}

void Game::runLoop() {
  isRunning = true;
  while (isRunning) {
    processInput();

    updateGame();

    generateOutput();
  }
}

void Game::updateGame() {
  //  _tick_count += SDL_GetTicks();
  eventSystem->System::update();
  playerControlSys->System::update();
}

void Game::generateOutput() { renderSys->System::render(); }

void Game::shutdown() {

  //  SDL_DestroyRenderer(_renderer);
  //  _renderer = nullptr;
  //  SDL_DestroyWindow(_window);
  //  _window = nullptr;
  //  SDL_Quit();
  renderSys->shutdown();
  playerControlSys->shutdown();
  eventSystem->shutdown();
}

// SDL_Renderer *Game::renderer() const { return _renderer; }

// SDL_Window *Game::window() const { return _window; }
