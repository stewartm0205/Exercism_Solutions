#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H
#include <math.h>
using namespace std;
namespace complex_numbers {
    class Complex {
        private:
            double r;
            double i;

        public:
            Complex (double r, double i) : r{r}, i{i} {}

            double real() const{
                return r;
            }   
            double imag() const{
                return i;
            } 
            Complex operator+ (Complex c2) const {
                double tr;
                double ti;
                tr = r + c2.r;
                ti = i + c2.i;
                return Complex(tr,ti);
            }
            Complex operator- (Complex c2) const {
                double tr;
                double ti;
                tr = r - c2.r;
                ti = i - c2.i;
                return Complex(tr,ti);
            }
            Complex operator* (Complex c2) const {
                double tr;
                double ti;
                tr = r * c2.r - i * c2.i;
                ti = r * c2.i + i * c2.r;
                return Complex(tr,ti);
            }
            Complex operator/ (Complex c2) const {
                double tr;
                double ti;
                tr = (r * c2.r + i * c2.i)/(c2.r*c2.r+ c2.i * c2.i);
                ti = (i * c2.r - r * c2.i)/(c2.r*c2.r+ c2.i * c2.i);
                return Complex(tr,ti);
            }
            double abs() const {
                return sqrt(r*r + i*i);
            }
            Complex conj() const {
                return Complex(r, -i);
            }
            Complex exp() const { 
                double tr;
                double ti;
                tr = std::exp(r) * cos(i);
                ti = std::exp(r) * sin(i);
                return Complex(tr, ti);
            }
    };
}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
