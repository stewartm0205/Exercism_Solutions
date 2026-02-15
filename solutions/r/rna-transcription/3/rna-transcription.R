to_rna <- function(dna) {
	rna <- ""
	d2r <- list("G"="C","C"="G","T"="A","A"="U")
	for (d in unlist(strsplit(dna, ""))) {
		r <- d2r[[d]]
		if (is.null(r)) { stop() }
		rna <- paste(rna, r, sep="")
		#print (d)
		#print (rna)
	}
	return (rna)
}
