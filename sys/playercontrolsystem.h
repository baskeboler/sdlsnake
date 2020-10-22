#ifndef PLAYERCONTROLSYSTEM_H
#define PLAYERCONTROLSYSTEM_H
//#include "../game.h"
#include "system.h"
#include <memory>

class Game;

class PlayerControlSystem : public System {
  //  std::shared_ptr<Game> _game;

public:
  PlayerControlSystem(std::shared_ptr<Game> g);
  virtual ~PlayerControlSystem() = default;

  // System interface
public:
  virtual void update(entt::registry &reg) override;
};

#endif // PLAYERCONTROLSYSTEM_H
