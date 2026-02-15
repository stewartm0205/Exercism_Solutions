// Package bob reponds to different types of queries like a surly teenager.
package bob

import "regexp"
import "strings"

// Hey returns a respond based on the type of remarks passed to it like a surly teenager.
func Hey(remark string) string {
	var match, _ = regexp.MatchString("^.*[A-Z]+.*[^\\?]$", remark)
	if match && remark == strings.ToUpper(remark) {
		return "Whoa, chill out!"
	}
	match, _ = regexp.MatchString("^.*[A-Z]+.*?$", remark)
	if match && remark == strings.ToUpper(remark) {
		return "Calm down, I know what I'm doing!"
	}
	match, _ = regexp.MatchString("^.*\\? *$", remark)
	if match {
		return "Sure."
	}
	match, _ = regexp.MatchString("^[ \\t\\n\\r]*$", remark)
	if match {
		return "Fine. Be that way!"
	}
	return "Whatever."
}
