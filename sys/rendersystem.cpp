#include "rendersystem.h"

//#include <sstream>
//#include <string>

//#include <SDL.h>
//#include <SDL2_gfxPrimitives.h>
//#include <SDL_render.h>

//#include "../components/all.h"
//#include "../game.h"

//#include <glm/gtx/matrix_transform_2d.hpp>

// RenderSystem::RenderSystem(std::shared_ptr<Game> g) : System{g} {}

// SDL_Surface *surface(int w, int h) {
//  return SDL_CreateRGBSurfaceWithFormat(0, w, h, 8, SDL_PIXELFORMAT_RGBA8888);
//}

// void renderRect(SDL_Renderer *renderer, int x, int y, int w, int h,
//                const glm::u8vec4 &color, bool filled) {
//  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
//  SDL_Rect r;
//  r.x = x;
//  r.y = y;
//  r.w = w;
//  r.h = h;
//  if (filled) {
//    SDL_RenderFillRect(renderer, &r);
//  } else {
//    SDL_RenderDrawRect(renderer, &r);
//  }
//}

// void renderCircle(SDL_Renderer *renderer, int x, int y, int rad,
//                  const glm::u8vec4 &color, bool filled) {
//  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

//  if (filled) {
//    filledCircleRGBA(renderer, x, y, rad, color.r, color.g, color.b, color.a);
//  } else {
//    circleRGBA(renderer, x, y, rad, color.r, color.g, color.b, color.a);
//  }
//}

// void RenderSystem::render(entt::registry &reg, SDL_Renderer *renderer) {
//  SDL_getFramerate(&fpsManager);
//  //  SDL_SetRenderDrawColor(renderer, 100, 255, 255, 255);
//  SDL_GL_SetSwapInterval(1);
//  glBegin(0);
//  glClearColor(255.0f, 0.0f, 0.0f, 255.0f);
//  //  SDL_RenderClear(renderer);
//  auto renderables = reg.view<Transform, Sprite>();

//  for (auto &e : renderables) {
//    auto &t = renderables.get<Transform>(e);
//    auto &s = renderables.get<Sprite>(e);
//    glPushMatrix();
//    glTranslatef(t.translate.x, t.translate.y, 0.0f);
//    //    glRotatef()
//    switch (s.type) {
//    case CIRCLE_FILLED:
//      renderCircle(renderer, t.translate.x, t.translate.y, s.width / 2.0,
//                   s.color, true);

//      break;
//    case CIRCLE_NOFILL:
//      renderCircle(renderer, t.translate.x, t.translate.y, s.width / 2.0,
//                   s.color, false);

//      break;
//    case RECT_FILLED:
//      //      renderRect(renderer, t.translate.x, t.translate.y, s.width,
//      //      s.height,
//      //                 s.color, true);
//      glColor3f(s.color.r, s.color.g, s.color.b);
//      glRectf(0.0f, 0.0f, s.width, s.height);
//      break;
//      //    case RECT_NOFILL:
//      //      renderRect(renderer, t.translate.x, t.translate.y, s.width,
//      //      s.height,
//      //                 s.color, false);
//      //      break;
//    default:
//      break;
//    }
//    glPopMatrix();
//    //    SDL_
//  }
//  glEnd();
//  std::stringstream ss;
//  ss << "fps: " << fpsManager.rateticks;
//  // stringRGBA(renderer, 0, 50, ss.str().c_str(), 0, 0, 0, 255);
//  //  SDL_RenderPresent(renderer);
//  SDL_GL_SwapWindow(this->game()->window());
//  //  glSwa
//}
