// The accumlate package executes a function against a list of strings
package accumulate
// The Accumulate function executes the tranform function against a list of string
func Accumulate(list []string, transform func(string) string) []string {
	var result []string
	for _, item := range list {
		result = append(result,transform(item))
	}
	return result
}
