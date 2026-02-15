// Package leap determines is a year is a leap year
package leap

// IsLeapYear takes a year as an argument and return true
// if the uear is a leap year otherwise it return false
func IsLeapYear(leap int) bool {
	return leap%400 == 0 || (leap%100 != 0 && leap%4 == 0)
}
