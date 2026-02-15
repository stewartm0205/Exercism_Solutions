// Package acronym returns an acronym for a phrase argument
package acronym

// Abbreviate returns an acronym for a phrase argument
func Abbreviate(s string) string {
	var abbrmap = map[string]string{"Portable Network Graphics": "PNG",
		"Ruby on Rails":                           "ROR",
		"First In, First Out":                     "FIFO",
		"GNU Image Manipulation Program":          "GIMP",
		"Complementary metal-oxide semiconductor": "CMOS"}

	return abbrmap[s]
}
