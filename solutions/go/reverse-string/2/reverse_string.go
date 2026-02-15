// Package reverse impliment code to reverse a string
package reverse
// Function Reverse reverse a string
func Reverse(input string) string {
	var revstr string = ""
	for _,l := range input {
		revstr = string(l) + revstr
	}
	return revstr
}
