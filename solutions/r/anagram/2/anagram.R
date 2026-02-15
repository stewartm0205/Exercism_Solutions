anagram <- function(subject, candidates) {
	testa <- function (cd, s) {
		if (tolower(s) != tolower(cd) && 
			tolower(paste0(sort(unlist(strsplit(s, ""))), collapse="")) == 
				tolower(paste0(sort(unlist(strsplit(cd, ""))), collapse=""))) {return(cd)}
	}
				
	return(unlist(lapply(candidates,  testa, s=subject)))
}
