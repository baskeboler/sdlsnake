#ifndef SPRITE_H
#define SPRITE_H

#include <glm/glm.hpp>

enum SpriteType {
  TEXTURE,
  CIRCLE_FILLED,
  CIRCLE_NOFILL,
  RECT_FILLED,
  RECT_NOFILL
};
struct Sprite {
  SpriteType type;
  int width;
  int height;
  glm::u8vec4 color;
};

#endif // SPRITE_H
