word_count <- function(input) {
wds <- unlist(strsplit(tolower(trimws(input)),"[,:!&@$%^ ]+"))
wc <- list()
	for (i in 1:length(wds)) {
		if (wds[i] %in% names(wc)) {
			wc[[wds[i]]] <- wc[[wds[i]]] + 1
		} else {
			wc[[wds[i]]] <- 1 
		}
	}	
return(wc)
}
