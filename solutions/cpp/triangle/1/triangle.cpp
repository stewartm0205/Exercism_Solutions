#include "triangle.h"

namespace triangle {
    enum flavor kind(float s1, float s2, float s3){
        if (s1<=0 || s2<=0 || s3<=0) throw std::domain_error("zero side");
        if (s1>s2+s3 || s2>s1+s3 || s3>s1+s2) throw std::domain_error("zero side");
        if (s1==s2 && s1==s3) return flavor::equilateral;
        if (s1==s2 || s1==s3 || s2==s3) return flavor::isosceles;
        return flavor::scalene;
    }
}  // namespace triangle
