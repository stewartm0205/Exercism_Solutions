// Package collatzconjecture proves the Collatz Conjecture for any number n
package collatzconjecture

import "errors"

// CollatzConjecture proves the Collatz Conjecture for its argument n
func CollatzConjecture(n int) (int, error) {

	if n < 1 {
		return 0, errors.New("bad arguments")
	}
	if n == 1 {
		return 0, nil
	}
	var count int
	for n > 1 {
		count++
		if (n % 2) == 0 {
			n = n / 2
		} else {
			n = 3*n + 1
		}
	}
	return count, nil

}
