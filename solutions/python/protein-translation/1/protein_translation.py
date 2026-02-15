""" Module to translate DNA codon to proteins"""
def proteins(strand):
    """ Function to translate DNA codon to proteins"""
    c_to_a = {"AUG":"Methionine", "UUU":"Phenylalanine", "UUC":"Phenylalanine",
              "UUA":"Leucine", "UUG":"Leucine", "UCU":"Serine", "UCC":"Serine",
              "UCA":"Serine", "UCG":"Serine", "UAU":"Tyrosine", "UAC":"Tyrosine",
              "UGU":"Cysteine", "UGC":"Cysteine", "UGG":"Tryptophan",
              "UAA":"STOP", "UAG":"STOP", "UGA":"STOP",}
    i = 0
    protein_list = []
    codon = ""
    while (i < len(strand) and codon not in ["UAA", "UAG", "UGA"]):
        codon = strand[i:i+3]
        if codon not in ["UAA", "UAG", "UGA"]:
            protein_list.append(c_to_a[codon])
        i += 3

    return protein_list
