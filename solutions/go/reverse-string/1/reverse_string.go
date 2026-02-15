// Package reverse impliment code to reverse a string
package reverse
import "fmt"
// Function Reverse reverse a string
func Reverse(input string) string {
	var revstr string = ""
	test := "robot"
	for _,l := range test {
		fmt.Println(l,string(l))
		revstr = revstr + string(l)
		fmt.Println(revstr)
	}
	return revstr
}
