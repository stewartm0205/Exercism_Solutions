// This package determines if a sentence is a pangram
package pangram
import "strings"

// This function determines if a sentence is a pangram
func IsPangram(input string) bool {
	var amap = make(map[string]int)
	alphabet := "abcdefghijklmnopqrstuvwxyz"
	for _,l := range alphabet {
		amap[string(l)]=0
	}
	for _,l := range input {
		amap[strings.ToLower(string(l))] = 1
	}
	for _,v := range amap{
		if v == 0 {
			return false
		}
	}
	return true
}
