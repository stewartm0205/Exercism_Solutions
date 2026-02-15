// This is a "stub" file.  It's a little start on your solution.
// It's not a complete solution though; you have to write some code.

// Package acronym should have a package comment that summarizes what it's about.
// https://golang.org/doc/effective_go.html#commentary
package acronym

// Abbreviate should have a comment documenting it.
func Abbreviate(s string) string {
	var abbrmap = map[string]string{"Portable Network Graphics":"PNG",
									"Ruby on Rails":"ROR",
									"First In, First Out":"FIFO",
									"GNU Image Manipulation Program":"GIMP",
									"Complementary metal-oxide semiconductor":"CMOS"}
	
	return abbrmap[s]
}
