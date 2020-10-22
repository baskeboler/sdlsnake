#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include "raylibrendersystem.h"
#include "system.h"
#include <entt/entt.hpp>
#include <functional>
#include <raylib.h>

class EventSystem : public System {
  entt::sigh<void(int)> signal_mousewheel;
  entt::sink<void(int)> signal_mousewheel_sink;

public:
  EventSystem(std::shared_ptr<Game> g);
  virtual ~EventSystem() = default;
  // System interface
public:
  virtual void init();
  virtual void shutdown();

  friend class Game;
  friend class RaylibRenderSystem;

protected:
  virtual void update(entt::registry &reg);
};

#endif // EVENTSYSTEM_H
