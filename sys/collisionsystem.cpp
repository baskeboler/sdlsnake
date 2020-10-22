#include "collisionsystem.h"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/adapted/boost_tuple.hpp>
#include <boost/geometry/geometries/adapted/c_array.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/io/io.hpp>

#include "../components/all.h"
#include "../game.h"

BOOST_GEOMETRY_REGISTER_C_ARRAY_CS(cs::cartesian)
BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)

namespace geo = boost::geometry;
namespace geoi = geo::index;

typedef geo::model::point<int, 2, geo::cs::cartesian> point_t;
typedef geo::model::box<point_t> box_t;
typedef geo::model::segment<point_t> segment_t;
typedef geo::model::linestring<point_t> linestring_t;
typedef geo::model::ring<point_t> ring_t;

typedef std::pair<box_t, int> geo_box_index_value_t;
typedef std::pair<point_t, int> geo_point_index_value_t;
typedef std::pair<segment_t, int> geo_segment_index_value_t;
typedef std::pair<linestring_t, int> geo_linestring_index_value_t;

CollisionSystem::CollisionSystem(std::shared_ptr<Game> g) : System{g} {}

void CollisionSystem::update(entt::registry &reg) {
  auto v = reg.view<snake::Sprite, snake::Alive, snake::Transform>();

  //  box_t b {}
}

void CollisionSystem::createCircle(int x, int y, float radius) {
  b2BodyDef def;
  def.type = b2_dynamicBody;
  def.position.Set(x, y);

  b2CircleShape shape;
  shape.m_p.Set(x, y);
  shape.m_radius = radius;

  auto body = world->CreateBody(&def);

  b2FixtureDef fixDef;
  fixDef.shape = &shape;
  fixDef.density = 1.f;
  auto fixture = body->CreateFixture(&fixDef);
}

void CollisionSystem::init() {
  b2Vec2 gravity{0.0f, -10.0f};
  world = new b2World{gravity};
}

void CollisionSystem::shutdown() {}
