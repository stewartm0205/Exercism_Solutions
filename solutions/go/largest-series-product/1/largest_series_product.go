// This package determines the largest product for a set sequences
package lsproduct

import ("strconv"
"errors"
)

// This function determines largest product for a certain size
// of numbers
func LargestSeriesProduct(digits string, span int) (int64, error) {
	var mp int64 = 0
	if span > len(digits) {
		return mp, errors.New("span greater than len of digits")
	}
	if len(digits)> 1 && span < 0 {
		return mp, errors.New("span less than 1")
	}
	for di := 0; di+span<=len(digits); di++ {
		var p int64 = 1
		for i := 0; i<span; i++ {
			v,err := strconv.Atoi(string(digits[di+i:di+i+1]))
			if err != nil {
				return 0,errors.New("Bad digit")
			}
			p *= int64(v)
		}
		if p>mp {mp=p}
	}
	return mp, nil
}
