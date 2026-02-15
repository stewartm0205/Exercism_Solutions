
// package etl will transform a scrabble scoring system
package etl
import "strings"

// Transform fill transform a map of value, letters to a map of letters, value
func Transform(in map[int][]string) map[string]int {
	result := make(map[string]int)

	for value, letters := range in {
		for _,letter := range letters {
			result[strings.ToLower(letter)] = value
		}
	}
	return result
}
