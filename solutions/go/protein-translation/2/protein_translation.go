//This package translates RNA seuences into proteins
package protein

import ("errors")

var (ErrStop error = errors.New("STOP")
     ErrInvalidBase error = errors.New("Invalid Base")
)

// The FromRNA breaks an RNA String into multiple Codons
func FromRNA(rna string) ([]string, error) {
 var proteins []string

 for i:= 0; i < len(rna); i =i+3 {

	protein, err := FromCodon(rna[i:i+3])
	if err == ErrStop {
		break
	}
	if err == ErrInvalidBase {
		return []string{}, err
	}
	proteins = append(proteins,protein)
 }
 return proteins, nil
}

// The FromCodon translate into protein
func FromCodon(codon string) (string, error) {
	var ctop = map[string]string {
		"AUG": "Methionine", "UUU":"Phenylalanine", "UUC": "Phenylalanine",
		"UUA":"Leucine", "UUG":"Leucine", "UCU": "Serine",
		"UCC": "Serine","UCA": "Serine","UCG": "Serine",
		"UAU":"Tyrosine","UAC":"Tyrosine","UGU":"Cysteine","UGC":"Cysteine",
		"UGG":"Tryptophan","UAA":"","UAG":"","UGA":"" }
	protein, ok := ctop[codon]

	if !ok {
		return "", ErrInvalidBase
	}
	if ctop[codon] == "" {
		return "", ErrStop
	}
	return protein, nil
}
