#pragma once
#include <cmath>

namespace raytrac {

  struct Vec3 {
    double x, y, z;
    Vec3(const double x = 0, const double y = 0, const double z = 0) : x(x), y(y), z(z) {}
    inline Vec3 operator+(const Vec3& b) const {
      return Vec3(x + b.x, y + b.y, z + b.z);
    }
    inline Vec3 operator-(const Vec3& b) const {
      return Vec3(x - b.x, y - b.y, z - b.z);
    }
    inline Vec3 operator-() const {
      return Vec3(-x, -y, -z);
    }
    inline Vec3 operator*(const double b) const {
      return Vec3(x * b, y * b, z * b);
    }
    inline Vec3 operator/(const double b) const {
      return Vec3(x / b, y / b, z / b);
    }
    inline const double length_squared() const {
      return x * x + y * y + z * z;
    }
    inline const double length() const {
      return sqrt(length_squared());
    }
  };
  inline Vec3 operator*(double f, const Vec3& v) {
    return v * f;
  }
  inline Vec3 normalize(const Vec3& v) {
    return v * (1.0 / v.length());
  }
  inline const Vec3 multiply(const Vec3& v1, const Vec3& v2) {
    return Vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
  }
  inline const double dot(const Vec3& v1, const Vec3& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  }
  inline const Vec3 cross(const Vec3& v1, const Vec3& v2) {
    return Vec3(
      (v1.y * v2.z) - (v1.z * v2.y),
      (v1.z * v2.x) - (v1.x * v2.z),
      (v1.x * v2.y) - (v1.y * v2.x));
  }
  const static Vec3 upVec3 = Vec3(0.1, 0);


  struct Vec2 {
    double x, y;
    Vec2(const double x = 0, const double y = 0) : x(x), y(y) {}
    inline Vec2 operator+(const Vec2& b) const {
      return Vec2(x + b.x, y + b.y);
    }
    inline Vec2 operator-(const Vec2& b) const {
      return Vec2(x - b.x, y - b.y);
    }
    inline Vec2 operator*(const double b) const {
      return Vec2(x * b, y * b);
    }
    inline Vec2 operator/(const double b) const {
      return Vec2(x / b, y / b);
    }
    inline const double length_squared() const {
      return x * x + y * y;
    }
    inline const double length() const {
      return sqrt(length_squared());
    }
  };
  inline Vec2 operator*(double f, const Vec2& v) {
    return v * f;
  }
  inline Vec2 normalize(const Vec2& v) {
    return v * (1.0 / v.length());
  }
  inline const Vec2 multiply(const Vec2& v1, const Vec3& v2) {
    return Vec2(v1.x * v2.x, v1.y * v2.y);
  }
  inline const double dot(const Vec2& v1, const Vec2& v2) {
    return v1.x * v2.x + v1.y * v2.y;
  }

};

