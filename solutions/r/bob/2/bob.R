bob <- function(input) {

if (input == toupper(input) &&  length(grep('^.*[A-Z]+.*[^\\?] *$',input,value=TRUE, perl=TRUE)) > 0) {
	return("Whoa, chill out!")
}

if (input == toupper(input) && length(grep('^.*[A-Z]+.*\\? *$',input,value=TRUE, perl=TRUE)) > 0) {
	return("Calm down, I know what I'm doing!")
}

if (length(grep('^.*\\? *$',input,value=TRUE)) > 0) {
	return ("Sure.")
}

if (length(grep('^[\\t\\r\\n ]*$',input,value=TRUE, perl=TRUE)) > 0) {
	return("Fine. Be that way!")
}

return("Whatever.")

}
