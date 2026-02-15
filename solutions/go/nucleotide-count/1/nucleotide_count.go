// The dna package counts the occurences of nucleotides in a DNA strand
package dna
import ("fmt")
// Histogram is a mapping from nucleotide to its count in given DNA.
// Choose a suitable data type.
type Histogram map[string]int

// DNA is a list of nucleotides. Choose a suitable data type.
type DNA = {string}

// Counts generates a histogram of valid nucleotides in the given DNA.
// Returns an error if d contains an invalid nucleotide.
///
// Counts is a method on the DNA type. A method is a function with a special receiver argument.
// The receiver appears in its own argument list between the func keyword and the method name.
// Here, the Counts method has a receiver of type DNA named d.
func (d DNA) Counts() (Histogram, error) {
	var h Histogram
	fmt.Printf("%T,%v",d,d)
	//for _,n := range d {
	//	fmt.Printf("%T,%v",n,n)
		//h[string(n)]++
	//}
	return h, nil
}
