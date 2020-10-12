#include <utility>

#include <SDL.h>

#include "playercontrolsystem.h"

#include "../components/all.h"
#include "../game.h"

PlayerControlSystem::PlayerControlSystem(std::shared_ptr<Game> g) : _game{g} {}

void PlayerControlSystem::update() {
  auto &reg = _game->registry();
  auto kb = SDL_GetKeyboardState(nullptr); //_game->getKbState();
  auto player = _game->getPlayerEntity();
  auto &transform = reg.get<Transform>(player);
  if (kb[SDL_SCANCODE_D]) {
    transform.translate.x++;
    reg.replace<Transform>(player, transform);
  }

  if (kb[SDL_SCANCODE_A]) {
    transform.translate.x--;
    reg.replace<Transform>(player, transform);
  }
}
