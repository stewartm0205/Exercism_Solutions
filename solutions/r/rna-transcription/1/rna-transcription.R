to_rna <- function(dna) {
	rna <- ""
	for (d in unlist(strsplit(dna, ""))) {
		if (d == "G") {r <- "C"}
		else if (d == "C") {r <- "G"}
		else if (d == "T") {r <- "A"}
		else if (d == "A") {r <- "U"}
		else { stop(error) }
		rna <- paste(rna, r, sep="")
		#print (d)
		#print (rna)
	}
	return (rna)
}
