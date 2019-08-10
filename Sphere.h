#pragma once
#include <cmath>

#include "Vec.h"
#include "Ray.h"
#include "Material.h"
#include "constant.h"
#include "intersection.h"

namespace raytrac {

  class Sphere {
  public:
    double radius;
    Vec3 position;
    Color emission;
    Color color;
    ReflectionType reflection_type;

    Sphere(const double radius, const Vec3& position, const Color& emission, const Color& color, const ReflectionType reflection_type) :
      radius(radius), position(position), emission(emission), color(color), reflection_type(reflection_type) {}

    // 入力のrayに対する交差点までの距離を返す。交差しなかったら0を返す。
    // rayとの交差判定を行う。交差したらtrue,さもなくばfalseを返す。
    bool intersect(const Ray& ray, Hitpoint* hitpoint) const;
  };

};

