//Package generates the musical scale
package scale
import "strings"

//Function generates teh musical scale
func Scale(tonic, interval string) []string {

	var snotes []string = []string{"A", "A#", "B","C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"}
	var fnotes []string = []string{"A", "Bb", "B","C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab"}
	var sharptonic []string = []string{"C","a","G","D","A","E","B","F#",
	                                   "e","b","f#","c#","g#","d#"}
	var scale []string

	if in(tonic,sharptonic) >= 0 {
		scale = snotes
	} else {
		scale = fnotes
	}
	if len(tonic) == 2 {
		tonic = strings.ToUpper(string(tonic[0]))+string(tonic[1])
	} else {
		tonic = strings.ToUpper(string(tonic[0]))
	}
	// find the position of the tonic
	if interval == "" {
		//chromatic scale
		return chromatic(tonic, scale)
	} else {
		//diatonic scale
		return diatonic(tonic,interval, scale)
	}
}

func in(item string, iarray []string) int {
var ii int
	for ii = 0; ii < len(iarray); ii++ {
		if item == iarray[ii] {
			return ii
		}
	}
	return -1
}

func chromatic(tonic string, scale []string) []string {
	var r []string
	var ti int = in(tonic, scale)
	for ni := ti; ni < len(scale); ni++ {
		r = append(r, scale[ni])
	}
	for ni := 0; ni < ti ; ni++ {
		r = append(r, scale[ni])
	}
	return r
}

func diatonic(tonic, interval string, scale []string) []string {
	var r []string
	var ti int = in(tonic, scale)

	r = append(r,scale[ti])

	for _, i := range interval {
		ti = ti + 1
		if ti > 11 {
			ti = 0
		}
		if string(i) == "M" {
			ti = ti + 1
			if ti > 11 {
				ti = 0
			}
		}
		if string(i) == "A" {
			ti = ti + 1
			if ti > 11 {
				ti = 0
			}
			ti = ti + 1
			if ti > 11 {
				ti = 0
			}
		}

		r = append(r,scale[ti])
	}
	r=r[:len(interval)]
	return r
}