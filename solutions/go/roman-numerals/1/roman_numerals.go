// This package provides the ability to convert arabic number to roman numerals
package romannumerals
import ("errors")
var d = []int{1000,900,500,400,100,90,50,40,10,9,5,4,1}
var itor = map[int]string{1000:"M",900:"CM",500:"D",400:"CD",100:"C",90:"XC",
     50:"L",40:"XL",10:"X",9:"IX",5:"V",4:"IV",1:"I"}
// The ToRomanNumeral function convert arabic number to roman numerals
func ToRomanNumeral(input int) (string, error) {
	var rnum string = ""
	if input < 1 {
		return "", errors.New("Must be 1 or greater")
	}
	if input > 3000 {
		return "", errors.New("Must be 3000 or less")
	}
	for di := 0; input > 0; {
		if d[di] <= input {
			input = input - d[di]
			rnum=rnum + itor[d[di]]
		} else {
			di++
		}
	}
	return rnum, nil
}
