#ifndef PLAYERCONTROLSYSTEM_H
#define PLAYERCONTROLSYSTEM_H
#include <memory>

class Game;

class PlayerControlSystem {
  std::shared_ptr<Game> _game;

public:
  PlayerControlSystem(std::shared_ptr<Game> g);

  void update();
};

#endif // PLAYERCONTROLSYSTEM_H
