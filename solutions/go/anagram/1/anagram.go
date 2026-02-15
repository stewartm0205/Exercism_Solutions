package anagram
import "strings"

func Detect(subject string, candidates []string) []string {
	var result []string
	var match bool
	subject = strings.ToLower(subject)
	for _,cand := range candidates {
		match = true
		lcand := strings.ToLower(cand)
		if subject != lcand && len(subject) == len(cand) {
			for _,l := range subject {
				p := strings.Index(lcand,string(l))
				if p < 0 {
					match = false
					break
				} else {
					lcand = lcand[:p]+lcand[p+1:]
				}
			}
			if match {
				result = append(result,cand)
			}
		}
	}
	return result
}
