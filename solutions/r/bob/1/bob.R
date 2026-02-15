bob <- function(input) {

# convert uppercase acronyms to lowercase
for (w in c("OK","DMV")) {
	#print (w)
	input=gsub(w,tolower(w),input)
	#print(input)
} 
#print(input)

if (length(grep('^.*[A-Z]{2,}.*[^?]$',input,value=TRUE, perl=TRUE)) > 0) {
	return("Whoa, chill out!")
}

if (length(grep('^.*[A-Z]{2,}.*\\? *$',input,value=TRUE, perl=TRUE)) > 0) {
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
