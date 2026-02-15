#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

collatz_conjecture.sh() {
	if [[ $# -eq 1 ]] && [[ $1 =~ [0-9]+ ]]
	then
		n=$1
		s=0
		if (( n < 1 )) 
		then
			echo "Error: Only positive numbers are allowed"
			return 1
		fi
		while (( n != 1 ))
		do
			let s=s+1
			if (( n % 2 == 0 )) 
			then
				let n=n/2
			else
				let n=3*n+1
			fi

		done
		echo $s
		return 0
	else
		echo "Usage: collatz_conjecture.sh <number>"
		return 1
	fi
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if collatz_conjecture.sh "$@"
then
	exit 0
else
	exit 1
fi

