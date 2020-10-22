#ifndef SPRITE_H
#define SPRITE_H

#include <glm/glm.hpp>
namespace snake {

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
} // namespace snake

#endif // SPRITE_H
