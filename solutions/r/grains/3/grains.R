square <- function(n) {
	if (n == 0) stop ("square 0 raises an exception")
	if (n < 0) stop ("negative square raises an exception")
	if (n > 64) stop ("square greater than 64 raises an exception")

	g <- 2^(n - 1)

	return (g)
}

total <- function() {
	tg <- sum(square(1:64))
	return (tg)
}
