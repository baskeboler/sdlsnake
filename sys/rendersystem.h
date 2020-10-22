#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "system.h"
#include <memory>
#include <utility>

class Game;

class RenderSystem : public System {

public:
  RenderSystem(std::shared_ptr<Game> g);

  // System interface
protected:
  //  virtual void render(entt::registry &reg) override;

  // System interface
public:
  //  void render();
};

#endif // RENDERSYSTEM_H
