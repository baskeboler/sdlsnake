#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "system.h"
#include <box2d/box2d.h>

class Game;

class CollisionSystem : public System {
  b2World *world;

public:
  CollisionSystem(std::shared_ptr<Game> g);
  virtual ~CollisionSystem() = default;
  // System interface
protected:
  virtual void update(entt::registry &reg);

  void createCircle(int x, int y, float radius);
  // System interface
public:
  virtual void init();
  virtual void shutdown();
};

#endif // COLLISIONSYSTEM_H
