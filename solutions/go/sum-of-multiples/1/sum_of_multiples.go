// Package sum of multiples
package summultiples

// Function generate sum of multiples
func SumMultiples(limit int, divisors ...int) int {

	var s int = 0
	var m []int
	for n:=1;n<limit;n++ {
		for _, d:= range divisors {
			//fmt.Println("d=",d)
			if d>0 && n%d == 0 {
				if !in(n,m) {
					m=append(m,n)
					s=s+n
				}
			}
		}
	}
	return s
}

func in(n int, m []int) bool {
	for _,v:= range m {
		if n == v {
			return true
		}
	}
	return false
}
