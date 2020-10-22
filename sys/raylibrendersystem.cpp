#include "raylibrendersystem.h"
#include "../components/all.h"
#include <memory>

#include <raylib.h>

RaylibRenderSystem::RaylibRenderSystem(std::shared_ptr<Game> g)

    : System{g} {}

void RaylibRenderSystem::init() {
  int windowWidth = this->game()->getWindowWidth();
  int windowHeight = this->game()->getWindowHeight();

  InitWindow(windowWidth, windowHeight, "raylib [core] example - basic window");

  _cam.zoom = 1.f;
  _cam.offset = {static_cast<float>(windowWidth / 2) + 20,
                 static_cast<float>(windowHeight / 2) + 30};
  _cam.rotation = 0.f;
  //  game()->
  //  _cam.

  game()
      ->eventSystem->signal_mousewheel_sink
      .connect<&RaylibRenderSystem::on_mousewheel_signal>(this);
  SetTargetFPS(60);
}

void RaylibRenderSystem::render(entt::registry &reg) {
  auto player = game()->getPlayerEntity();

  auto renderables = reg.view<snake::Transform, snake::Sprite>();
  BeginDrawing();
  BeginMode2D(_cam);
  auto &playerTransform = renderables.get<snake::Transform>(player);
  _cam.target = {playerTransform.translate.x, playerTransform.translate.y};
  ClearBackground(RAYWHITE);
  for (auto &e : renderables) {
    auto &t = renderables.get<snake::Transform>(e);
    auto &s = renderables.get<snake::Sprite>(e);

    switch (s.type) {

    case snake::CIRCLE_FILLED: {
      DrawCircle(t.translate.x, t.translate.y, s.width,
                 {s.color.r, s.color.g, s.color.b, s.color.a});
      break;
    }
    case snake::CIRCLE_NOFILL: {
      DrawCircleLines(t.translate.x, t.translate.y, s.width,
                      {s.color.r, s.color.g, s.color.b, s.color.a});
      break;
    }
    case snake::RECT_FILLED: {
      Rectangle rect{t.translate.x, t.translate.y, static_cast<float>(s.width),
                     static_cast<float>(s.height)};
      DrawRectanglePro(rect, {.5f * s.width, .5f * s.height}, t.rotate,
                       {s.color.r, s.color.g, s.color.b, s.color.a});
      break;
    }

    case snake::RECT_NOFILL: {
      DrawRectangleLines(t.translate.x, t.translate.y, s.width, s.height,
                         {s.color.r, s.color.g, s.color.b, s.color.a});
      break;
    }
    default:
      break;
    }
  }
  EndMode2D();
  DrawText("Hello", 20, 20, 50, BLACK);
  //  DrawCircle(100, 100, 30.f, PURPLE);
  EndDrawing();
}

void RaylibRenderSystem::shutdown() { CloseWindow(); }
