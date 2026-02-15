
// Package triangle determines what kind of triangle a triangle is
package triangle

import ("math"
		)

// Notice KindFromSides() returns this type. Pick a suitable data type.
type Kind int

const (
    // Pick values for the following identifiers used by the test program.
    NaT = iota // not a triangle
    Equ // equilateral
    Iso // isosceles
    Sca // scalene
)

// KindFromSides is a function that determines what kind of sides a triangle has.
func KindFromSides(a, b, c float64) Kind {

	if math.IsNaN(a) || math.IsNaN(b) || math.IsNaN(c) {
		return NaT
	}

	if math.IsInf(a,-1) || math.IsInf(b,-1) || math.IsInf(c,-1) ||
	   math.IsInf(a,1) || math.IsInf(b,1) || math.IsInf(c,1){
		return NaT
	}

	if a<=0.0 || b<=0.0 || c<= 0.0 {
		return NaT
	}

	if a+b < c || a+c <b || b+c < a {
		return NaT
	}


	if a==b && b == c {
		return Equ
	} else if a==b || a==c || b==c {
		return Iso
	}

	return Sca
}
