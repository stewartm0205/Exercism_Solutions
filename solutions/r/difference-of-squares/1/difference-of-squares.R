# this is a stub function that takes a natural_number
# and should return the difference-of-squares as described
# in the README.md
s1 <- 0
s2 <- 0
difference_of_squares <- function(natural_number) {
	for (n in 1:natural_number) {
		s1 <- s1 + n
		s2 <- s2 + n * n
	}
	return(s1 * s1 - s2)
}
