#ifndef SYSTEM_H
#define SYSTEM_H

#include <entt/entt.hpp>
#include <memory>

class Game;

class System {

  std::shared_ptr<Game> _game;

public:
  System(std::shared_ptr<Game> _game);
  virtual ~System() = default;

  void update();
  void render();

  virtual void init(){};
  virtual void shutdown() {}

protected:
  virtual void update(entt::registry &reg) {}
  virtual void render(entt::registry &reg) {}

  std::shared_ptr<Game> game() const;
};

#include "../game.h"
#endif // SYSTEM_H
