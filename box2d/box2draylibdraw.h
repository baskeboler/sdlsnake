#ifndef BOX2DRAYLIBDRAW_H
#define BOX2DRAYLIBDRAW_H

#include <box2d/b2_draw.h>

namespace snake {

class Box2DRaylibDraw : public b2Draw {
public:
  Box2DRaylibDraw();
  virtual ~Box2DRaylibDraw() = default;
  // b2Draw interface
public:
  virtual void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount,
                           const b2Color &color);
  virtual void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount,
                                const b2Color &color);
  virtual void DrawCircle(const b2Vec2 &center, float radius,
                          const b2Color &color);
  virtual void DrawSolidCircle(const b2Vec2 &center, float radius,
                               const b2Vec2 &axis, const b2Color &color);
  virtual void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2,
                           const b2Color &color);
  virtual void DrawTransform(const b2Transform &xf);
  virtual void DrawPoint(const b2Vec2 &p, float size, const b2Color &color);
};
} // namespace snake

#endif // BOX2DRAYLIBDRAW_H
