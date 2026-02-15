square <- function(n) {
	if (n == 0) stop ("square 0 raises an exception")
	if (n < 0) stop ("negative square raises an exception")
	if (n > 64) stop ("square greater than 64 raises an exception")
	g <- 1
	if (n > 1) {
		for (i in 2:n) {
			g <- g * 2
		}
	}
	return (g)
}

total <- function() {
	tg <- 0
	for (n in 1:64) {
		tg <- tg + square(n)
	}
	return (tg)
}
