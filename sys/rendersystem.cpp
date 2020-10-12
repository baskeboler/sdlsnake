#include "rendersystem.h"
#include "../game.h"

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

#include "../components/all.h"

RenderSystem::RenderSystem(std::shared_ptr<Game> g) : _game{g} {}

SDL_Surface *surface(int w, int h) {
  return SDL_CreateRGBSurfaceWithFormat(0, w, h, 8, SDL_PIXELFORMAT_RGBA8888);
}

void renderRect(SDL_Renderer *renderer, int x, int y, int w, int h,
                const glm::u8vec4 &color, bool filled) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_Rect r;
  r.x = x;
  r.y = y;
  r.w = w;
  r.h = h;
  if (filled) {
    SDL_RenderFillRect(renderer, &r);
  } else {
    SDL_RenderDrawRect(renderer, &r);
  }
}

void renderCircle(SDL_Renderer *renderer, int x, int y, int rad,
                  const glm::u8vec4 &color, bool filled) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

  if (filled) {
    filledCircleRGBA(renderer, x, y, rad, color.r, color.g, color.b, color.a);
    //    SDL_RenderFillRect(renderer, &r);
  } else {
    circleRGBA(renderer, x, y, rad, color.r, color.g, color.b, color.a);
    //    SDL_RenderDrawRect(renderer, &r);
  }
}

void RenderSystem::render() {
  auto game = _game;
  auto &reg = game->registry();
  SDL_Renderer *renderer = game->renderer();
  SDL_SetRenderDrawColor(renderer, 100, 255, 255, 255);
  SDL_RenderClear(renderer);
  auto renderables = reg.view<Transform, Sprite>();

  for (auto &e : renderables) {
    auto &t = renderables.get<Transform>(e);
    auto &s = renderables.get<Sprite>(e);

    switch (s.type) {
    case CIRCLE_FILLED:
      renderCircle(renderer, t.translate.x, t.translate.y, s.width / 2.0,
                   s.color, true);

      break;
    case CIRCLE_NOFILL:
      renderCircle(renderer, t.translate.x, t.translate.y, s.width / 2.0,
                   s.color, false);

      break;
    case RECT_FILLED:
      renderRect(renderer, t.translate.x, t.translate.y, s.width, s.height,
                 s.color, true);
      break;
    case RECT_NOFILL:
      renderRect(renderer, t.translate.x, t.translate.y, s.width, s.height,
                 s.color, false);
      break;
    default:
      break;
    }

    //    SDL_
  }
  SDL_RenderPresent(renderer);
}
