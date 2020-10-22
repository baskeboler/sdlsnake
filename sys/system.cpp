#include "system.h"
#include "../game.h"

System::System(std::shared_ptr<Game> _game) : _game{_game} {}

void System::update() {
  auto &reg = _game->registry();
  update(reg);
}

void System::render() {
  auto &reg = _game->registry();
  render(reg);
}

std::shared_ptr<Game> System::game() const { return _game; }
