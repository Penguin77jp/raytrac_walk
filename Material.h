#pragma once
#include "Vec.h"

namespace raytrac {

  typedef Vec3 Color;

  enum ReflectionType {
    REFLECTION_TYPE_DIFFUSE,	// 完全拡散面。いわゆるLambertian面。
    REFLECTION_TYPE_SPECULAR,	// 理想的な鏡面。
    REFLECTION_TYPE_REFRACTION,	// 理想的なガラス的物質。
  };

};

