#include "game.h"
#include "components/all.h"
#include <algorithm>
#include <vector>

entt::registry &Game::registry() { return _registry; }

std::vector<Uint8> Game::getKbState() const { return kbState; }

entt::entity Game::getPlayerEntity() const { return playerEntity; }

void Game::processInput() {
  SDL_Event evt;
  while (SDL_PollEvent(&evt)) {

    switch (evt.type) {
    case SDL_QUIT:
      _is_running = false;
      break;
    }
  }

  int len = 0;
  const Uint8 *state = SDL_GetKeyboardState(&len);
  //  std::vector<Uint8> {}
  kbState.clear();
  kbState.reserve(len);
  for (int i = 0; i < len; i++) {
    kbState[i] = state[i];
  }

  if (kbState[SDL_SCANCODE_ESCAPE]) {
    _is_running = false;
  }
  if (kbState[SDL_SCANCODE_SPACE]) {
    SDL_Log("space key was pressed");
  }
  if (kbState[SDL_SCANCODE_RIGHT]) {
    SDL_Log("space key was pressed");
  }
}

Game::Game(SDL_Window *w, SDL_Renderer *renderer, bool r, const std::string &t,
           int ww, int wh)
    : _window{w}, _renderer{renderer}, _is_running{r}, _title{t},
      _tick_count{0}, _windowWidth{ww}, _windowHeight{wh} {}

Game::~Game() {
  if (_window || _renderer) {
    shutdown();
  }
}

bool Game::initialize() {
  int res = SDL_Init(SDL_INIT_EVERYTHING);
  if (res != 0) {
    SDL_Log("Unable to initilize SDL: %s", SDL_GetError());
    return false;
  }

  _window =
      SDL_CreateWindow(_title.c_str(), 100, 100, 1024, 768, SDL_WINDOW_OPENGL);
  if (!_window) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }

  _renderer = SDL_CreateRenderer(
      _window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!_renderer) {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return false;
  }

  renderSys = std::make_unique<RenderSystem>(shared_from_this());
  playerControlSys = std::make_unique<PlayerControlSystem>(shared_from_this());
  playerEntity = _registry.create();
  _registry.emplace<Transform>(playerEntity, 100, 100);
  glm::u8vec4 color = {0, 255, 0, 255};
  _registry.emplace<Sprite>(playerEntity, CIRCLE_FILLED, 100, 100, color);
  return true;
}

void Game::runLoop() {
  _is_running = true;
  while (_is_running) {
    processInput();

    updateGame();

    generateOutput();
  }
}

void Game::updateGame() {
  _tick_count += SDL_GetTicks();
  playerControlSys->update();
}

void Game::generateOutput() { renderSys->render(); }

void Game::shutdown() {

  SDL_DestroyRenderer(_renderer);
  _renderer = nullptr;
  SDL_DestroyWindow(_window);
  _window = nullptr;
  SDL_Quit();
}

SDL_Renderer *Game::renderer() const { return _renderer; }

SDL_Window *Game::window() const { return _window; }
