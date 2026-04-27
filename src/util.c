#include "util.h"

/// ///

uint8_t radToByte(const float rad) { return (rad / M_2PIf) * 256.0f; }

uint8_t angToByte(const float ang) { return (ang / 360.0f) * 256.0f; }

float degToRad(const float ang) { return ang * (M_PIf / 180.0f); }

float len(const float x1, const float x2, const float y1, const float y2) {
  return sqrtf( len2(x1, x2, y1, y2) );
}

float len2(const float x1, const float x2, const float y1, const float y2) {
  return powf(x1 - x2, 2) + powf(y1 - y2, 2);
}