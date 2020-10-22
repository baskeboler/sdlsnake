#ifndef POSITION_H
#define POSITION_H

#include <glm/glm.hpp>

namespace snake {

struct Transform {

  glm::fvec2 translate = {0, 0};
  float rotate = 0;
  glm::fvec2 scale = {1, 1};
  Transform(float translateX = 0, float translateY = 0, float rotate = 0,
            float scaleX = 1, float scaleY = 1)
      : translate{translateX, translateY}, rotate{rotate}, scale{scaleX,
                                                                 scaleY} {}
};
} // namespace snake

#endif // POSITION_H
