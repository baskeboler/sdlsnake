#ifndef RAYLIBRENDERSYSTEM_H
#define RAYLIBRENDERSYSTEM_H

#include "system.h"
#include <raylib.h>

class RaylibRenderSystem : public System {
  Camera2D _cam;

public:
  RaylibRenderSystem(std::shared_ptr<Game> g);

  virtual ~RaylibRenderSystem() = default;
  // System interface
protected:
  virtual void init();
  virtual void render(entt::registry &reg);

  virtual void shutdown();

  void on_mousewheel_signal(int i) { _cam.zoom += i * .1f * _cam.zoom; }
};

#endif // RAYLIBRENDERSYSTEM_H
