// Package strand transcripts a DNA strand into its RNA complement
package strand

// ToRNA takes a DNA strand as an argument a returns its RNA complement
func ToRNA(dna string) string {
	rna := ""
	for _, dnaC := range(dna) {
		switch dnaC {
		case 'G':
			rna = rna + "C"
		case 'C':
			rna = rna + "G"
		case 'T':
			rna = rna + "A"
		case 'A':
			rna = rna + "U"
		}
	}
	return rna
}
