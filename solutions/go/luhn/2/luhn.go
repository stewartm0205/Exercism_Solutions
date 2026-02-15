// Package luhn implements a checksum formula to validate
// credit card numbers
package luhn

import (
		"strconv"
		"strings"
)

// Valid function determines if its arg num is valid and has a valid
// checksum
func Valid(num string) bool {
	// strip spaces out
	num = strings.ReplaceAll(num," ","")
	if len(num) == 1 {
		return false
	}
	sum := 0
	for i := len(num) - 2; i >= 0; i = i - 2 {
		c := string(num[i])
		d, err := strconv.Atoi(c)
		if err != nil {
			return false
		}
		d = d * 2
		if d > 9 {
			d = d - 9
		}
		sum += d
	}
	for i := len(num) - 1; i >= 0; i = i - 2 {
		c := string(num[i])
		d, err := strconv.Atoi(c)
		if err != nil {
			return false
		}
		sum += d
	}
	if sum % 10 == 0 {
		return true
	}
	return false

}

