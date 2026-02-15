#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

raindrops.sh() {
	if [[ $# -eq 1 ]] && [[ $1 =~ [0-9]+ ]]
	then
		n=$1
		r=""

		if ((n % 3 == 0))  || ((n % 5 == 0)) || ((n % 7 == 0))
		then
			if ((n % 3 == 0)) 
			then
				r=${r}"Pling"
			fi

			if ((n % 5 == 0)) 
			then
				r=${r}"Plang"
			fi

			if ((n % 7 == 0)) 
			then
				r=${r}"Plong"
			fi
		else
			r=$n
		fi
		echo $r
		return 0
	else
		echo "Usage: raindrops.sh <number>"
		return 1
	fi
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if raindrops.sh "$@"
then
	exit 0
else
	exit 1
fi

