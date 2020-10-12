#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <memory>
#include <utility>

class Game;

class RenderSystem {
  std::shared_ptr<Game> _game;

public:
  RenderSystem(std::shared_ptr<Game> g);

  void render();
};

#endif // RENDERSYSTEM_H
