// Package encode compresses and decompresses a string of characters
package encode
import ("strings"
		"unicode"
        "strconv"
		)

//function RunLengthEncode - compresses a string of characters
func RunLengthEncode(input string) string {
	result :=""
	pc := ""
	cc := 0
	for _,c := range input {
		if pc == "" {
			pc = string(c)
			cc = 1
		} else if pc == string(c) {
			cc++
		} else {
			if cc <= 1 {
				result = result + pc
			} else {
				result = result + strconv.Itoa(cc) + pc
			}
			pc = string(c)
			cc = 1
		}
	}
	if cc <= 1 {
		result = result + pc
	} else {
		result = result + strconv.Itoa(cc) + pc
	}
	return result
}

//function RunLengthDecode - decompresses a string of characters
func RunLengthDecode(input string) string {
	result := ""
	cc := ""
	for _,c := range input {
		if unicode.IsDigit(c) {
			cc = cc + string(c)
		} else {
			if cc=="" {
				result += string(c)
			} else {
				k,_ := strconv.Atoi(cc)
				result += strings.Repeat(string(c), k)
				cc = ""
			}
		}
	}
	return result
}
