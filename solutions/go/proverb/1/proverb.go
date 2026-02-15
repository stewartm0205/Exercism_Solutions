
// Package proverb generates lines of a poem for a string array
package proverb

import ( "fmt")

// The Proverb function will return lines of poems giving the rhyme string array
func Proverb(rhyme []string) []string {
	var poem []string
	if len(rhyme) == 0 {
		return []string{}
	}
	word1 := rhyme[0]
	
	for wi := 1; wi < len(rhyme); wi++ {
		word2 := rhyme[wi]
		poem = append(poem, fmt.Sprintf("For want of a %v the %v was lost.", word1, word2))
		word1 = word2
	}
	poem = append(poem, fmt.Sprintf("And all for the want of a %v.", rhyme[0]))
	return poem
}
