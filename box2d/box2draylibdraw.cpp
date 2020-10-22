#include "box2draylibdraw.h"
#include <raylib.h>

namespace snake {

Box2DRaylibDraw::Box2DRaylibDraw() {}

void Box2DRaylibDraw::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount,
                                  const b2Color &color) {
  Vector2 *vs = new Vector2[vertexCount];
  for (int i = 0; i < vertexCount; i++) {
    const b2Vec2 &v = vertices[i];
    vs[i].x = v.x;
    vs[i].y = v.y;
  }
  Color c = {static_cast<unsigned char>(256 * color.r),
             static_cast<unsigned char>(256 * color.g),
             static_cast<unsigned char>(256 * color.b),
             static_cast<unsigned char>(256 * color.a)};
  DrawTriangleStrip(vs, vertexCount, c);
  delete[] vs;
}

void Box2DRaylibDraw::DrawSolidPolygon(const b2Vec2 *vertices,
                                       int32 vertexCount,
                                       const b2Color &color) {
  Vector2 *vs = new Vector2[vertexCount];
  for (int i = 0; i < vertexCount; i++) {
    const b2Vec2 &v = vertices[i];
    vs[i].x = v.x;
    vs[i].y = v.y;
  }
  Color c = {static_cast<unsigned char>(256 * color.r),
             static_cast<unsigned char>(256 * color.g),
             static_cast<unsigned char>(256 * color.b),
             static_cast<unsigned char>(256 * color.a)};
  DrawTriangleStrip(vs, vertexCount, c);
  delete[] vs;
}

void Box2DRaylibDraw::DrawCircle(const b2Vec2 &center, float radius,
                                 const b2Color &color) {
  Color c = {static_cast<unsigned char>(256 * color.r),
             static_cast<unsigned char>(256 * color.g),
             static_cast<unsigned char>(256 * color.b),
             static_cast<unsigned char>(256 * color.a)};

  ::DrawCircleLines(center.x, center.y, radius, c);
}

void Box2DRaylibDraw::DrawSolidCircle(const b2Vec2 &center, float radius,
                                      const b2Vec2 &axis,
                                      const b2Color &color) {
  Color c = {static_cast<unsigned char>(256 * color.r),
             static_cast<unsigned char>(256 * color.g),
             static_cast<unsigned char>(256 * color.b),
             static_cast<unsigned char>(256 * color.a)};

  ::DrawCircle(center.x, center.y, radius, c);
}

void Box2DRaylibDraw::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2,
                                  const b2Color &color) {
  Color c = {static_cast<unsigned char>(256 * color.r),
             static_cast<unsigned char>(256 * color.g),
             static_cast<unsigned char>(256 * color.b),
             static_cast<unsigned char>(256 * color.a)};

  DrawLine(p1.x, p1.y, p2.x, p2.y, c);
}

void Box2DRaylibDraw::DrawTransform(const b2Transform &xf) {}

void Box2DRaylibDraw::DrawPoint(const b2Vec2 &p, float size,
                                const b2Color &color) {
  Color c = {static_cast<unsigned char>(256 * color.r),
             static_cast<unsigned char>(256 * color.g),
             static_cast<unsigned char>(256 * color.b),
             static_cast<unsigned char>(256 * color.a)};

  ::DrawCircle(p.x, p.y, size, c);
}
} // namespace snake
