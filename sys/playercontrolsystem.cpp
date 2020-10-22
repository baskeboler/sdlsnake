#include "playercontrolsystem.h"

#include <utility>

#include <boost/geometry.hpp>
#include <raylib.h>

#include "../components/all.h"
#include "../game.h"

namespace geo = boost::geometry;
PlayerControlSystem::PlayerControlSystem(std::shared_ptr<Game> g) : System{g} {}

void PlayerControlSystem::update(entt::registry &reg) {
  auto player = game()->getPlayerEntity();
  auto &sprite = reg.get<snake::Sprite>(player);
  sprite.color.r = (sprite.color.r + 1) % 256;
  auto &transform = reg.get<snake::Transform>(player);
  if (IsKeyDown(KEY_D)) {
    transform.translate.x += 5;
  }

  if (IsKeyDown(KEY_A)) {
    transform.translate.x -= 5;
  }
  if (IsKeyDown(KEY_W)) {
    transform.translate.y -= 5;
  }
  if (IsKeyDown(KEY_S)) {
    transform.translate.y += 5;
  }
  if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) {
    game()->signalClose();
  }

  auto enemies = reg.view<snake::Enemy, snake::Transform>();
  for (auto &e : enemies) {
    auto &t = reg.get<snake::Transform>(e);
    t.rotate++;
  }
}
