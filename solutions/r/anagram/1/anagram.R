anagram <- function(subject, candidates) {
	r<-c()
	for (cd in candidates) {
		if (tolower(subject) != tolower(cd)) { # ignore identical words 
			if (tolower(paste0(sort(unlist(strsplit(subject, ""))), collapse="")) == 
				tolower(paste0(sort(unlist(strsplit(cd, ""))), collapse=""))) {
				r<-c(r,cd)
			}
		}
	}
	return (r)
}
