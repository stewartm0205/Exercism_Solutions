raindrops <- function(number) {
	factors <- function (n) {
		#print(c("n=", n))
		if (n == 1) {return (c(1))}
		for (d in 1:(n %/% 2)) {
			#print ("d=",d)
			if (d == 1) {
				f <- c(1) 
			} else if  (n %% d == 0)
			{
				f <- c(f, d)
				#print(c("f=",f))
			}			
		}
		f <- c(f,n)
		return (f)
	} 
	
	rd <- ""
	for (f in factors(number)) {
		if (f == 3) { rd <- paste(rd,"Pling", sep="")}
		if (f == 5) { rd <- paste(rd,"Plang", sep="")}
		if (f == 7) { rd <- paste(rd,"Plong", sep="")}
	}
	if (rd == "") { rd <- as.character(number) }
	return(rd)

}


