import re
def hey(phrase):
	
	if re.search('^[\t\r\n ]*$',phrase):
		return 'Fine. Be that way!'

	if phrase.upper() == phrase and re.search('^.*[a-zA-Z]+.*\\? *$', phrase):
		return "Calm down, I know what I'm doing!"
		
	if phrase.upper() == phrase and re.search('^.*[a-zA-Z]+.*[^\\?] *$', phrase):
		return "Whoa, chill out!"
			
	if re.search('^.*\\? *$', phrase):
		return 'Sure.' 

	return "Whatever."
