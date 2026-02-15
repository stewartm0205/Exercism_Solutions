// This is a "stub" file.  It's a little start on your solution.
// It's not a complete solution though; you have to write some code.

// Package bob should have a package comment that summarizes what it's about.
// https://golang.org/doc/effective_go.html#commentary
package bob

import "regexp"
import "strings"
//import "fmt"

// Hey should have a comment documenting it.
func Hey(remark string) string {
	// replace uppercase acronyms with lowercase
	var a = []string {"OK","DMV"}
	for i := 0; i<len(a); i++ {
		remark = strings.Replace(remark, a[i], strings.ToLower(a[i]), -1)
		//fmt.Println(remark)
	}
	var match, _ = regexp.MatchString(".+[A-Z]+.*[^\\?]$",remark)
	if (match) {return "Whoa, chill out!"}
	match, _ = regexp.MatchString(".+[A-Z]{2,}.*?$",remark)
	if (match) {return "Calm down, I know what I'm doing!"}
	match, _ = regexp.MatchString("^.*\\? *$",remark)
	if (match) {return "Sure."}
	match, _ = regexp.MatchString("^[ \\t\\n\\r]*$",remark)
	if (match) {return "Fine. Be that way!"}
	return "Whatever."
}
