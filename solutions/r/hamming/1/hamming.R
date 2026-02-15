# This is a stub function to take two strings
# and calculate the hamming distance
hamming <- function(strand1, strand2) {
	if (nchar(strand1) == nchar(strand2)) {
		h <- 0
		for (i in 1:nchar(strand1)) {
			if (substr(strand1, i, i) != substr(strand2, i, i)) { h <- h + 1}
		}
		return (h)
	} else {
		stop("error")
	}
}
