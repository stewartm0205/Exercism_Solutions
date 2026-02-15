def to_rna(dna_strand):
    DNARNA = {"G":"C", "C":"G", "T":"A", "A":"U"}
    rna_strand=""
    for a in dna_strand:
        if a in "GCTA":
            rna_strand += DNARNA[a]
        else:
            raise ValueError("Value Error")
    return(rna_strand)

#print (to_rna("GCTA"))
#print (to_rna("F"))