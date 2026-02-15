//This package translates RNA seuences into proteins
package protein

import ("fmt"
"errors")

const ErrStop=1
const ErrInvalidBase=2

// The FromRNA breaks an RNA String into multiple Codons
func FromRNA(rna string) ([]string, error) {
 var result []string
 for i:= 0; i < len(rna); i =i+3 {
	fmt.Println(rna[3*i:3*i+3])
	result[i/3] = rna[3*i:3*i+3]
 }
 return result, nil
}

// The FromCodon translate into protein
func FromCodon(codon string) (string, error) {
	var ctop = map[string]string {
		"AUG": "Methionine", "UUU":"Phenylalanine", "UUC": "Phenylalanine",
		"UUA":"Leucine", "UUG":"Leucine", "UCG": "Serine",
		"UAU":"Tyrosine","UAC":"Tyrosine","UGU":"Cysteine",
		"UGG":"Tryptophan","UAA":"","UAG":"","UGA":"" }
	protein, ok := ctop[codon]
	if !ok {
		return "", errors.ErrInvalidBase
	}
	if ctop[codon] == "" {
		return "", errors.ErrStop
	}
	return protein, nil
}
