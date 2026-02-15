// wordcount implements a package to countthe numbers of words.
package wordcount

import "strings"


type Frequency map[string]int
// function WordCount counts the number of times a word appears in a phrase
func WordCount(phrase string) Frequency {
	wc := make(Frequency)
	phrase = strings.ToLower(phrase)
	ephrase :=""
	for _,v := range phrase {
		if (string(v)>="a" && string(v)<="z")||
		   (string(v)>="0" && string(v)<="9")|| string(v)=="'" {
			ephrase = ephrase + string(v)
		} else {
			ephrase = ephrase + " "
		}
	}
	words := strings.Fields(ephrase)
	for _,w := range words {
		if string(w[0])=="'" {
			w=w[1:]
		}
		if string(w[len(w)-1:])=="'" {
			 w=w[:len(w)-1]
		}
		wc[w] += 1
	}
	return wc
}
