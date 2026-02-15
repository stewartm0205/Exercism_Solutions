// Package diffsquares calculates the difference between the square of the sum of first nth numbers in the series and the sum of the square of the same numbers.
package diffsquares

// SquareOfSum returns the square of the sum of the series of numbers from 1 to its argument n
func SquareOfSum(n int) int {
	var sum int
	for i := 1; i <= n; i++ {
		sum += i
	}
	return sum * sum
}

// SumOfSquares returns the sum of the series of numbers from 1 to its argument n squared
func SumOfSquares(n int) int {
	var sum int
	for i := 1; i <= n; i++ {
		sum += i * i
	}
	return sum
}

// Difference returns the sum of the series of numbers from 1 to its argument n squared
func Difference(n int) int {
	return SquareOfSum(n) - SumOfSquares(n)
}
