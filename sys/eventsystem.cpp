#include "eventsystem.h"

EventSystem::EventSystem(std::shared_ptr<Game> g)
    : System{g}, signal_mousewheel_sink{signal_mousewheel} {}

void EventSystem::init() {}

void EventSystem::shutdown() {}

void EventSystem::update(entt::registry &reg) {
  int delta = GetMouseWheelMove();
  if (delta != 0) {
    signal_mousewheel.publish(delta);
  }
}
