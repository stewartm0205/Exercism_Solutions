#if !defined(TRIANGLE_H)
#define TRIANGLE_H
#include <exception>
#include <stdexcept>

namespace triangle {
  enum flavor {
      equilateral,
      isosceles,
      scalene
  } ; 
enum flavor kind(float s1, float s2, float s3);
}  // namespace triangle

#endif // TRIANGLE_H