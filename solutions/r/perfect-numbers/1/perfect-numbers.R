number_type <- function(n){
	factors <- function (n) {
		if (n == 1) {return (c())}
		for (d in 1:(n %/% 2)) {
			if (d == 1) {
				f <- c(1) 
			} else if  (n %% d == 0)
			{
				f <- c(f, d)
			}			
		}
		return (f)
	}
	sf <- sum(factors (n))
	if (sf == n) 
	{ 
		return ("perfect") 
	} else if (sf > n) 
	{
		return ("abundant")
	} else 
	{
		return ("deficient")
	}
}
