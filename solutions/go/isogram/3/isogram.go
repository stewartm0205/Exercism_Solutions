// Package isogram returns true is the argument is an isogram else return false
package isogram

import "strings"

// IsIsogram determines is is argument is an isogram
func IsIsogram(word string) bool {
	var cc [26]int
	for _, c := range []rune(strings.ToLower(word)) {
    if c >= 'a' && c <='z' {
		  cc[int(c)-int('a')]++
		  if cc[int(c)-int('a')] > 1 {
			  return false
		  }
    }
	}
	return true
}
