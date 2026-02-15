#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

armstrong_numbers() {
  if [ $# -lt 1 ]
  then
          echo "Usage: armstrong_numbers.sh <number>"
          return 1
  elif [ $# -gt 1 ]
  then
          echo "Usage: armstrong_numbers.sh <number>"
          return 1
  else
          n=$1
          if [[ $n =~ ^[0-9]+$ ]]
          then
		nd=${#n}
		#echo $nd
		s=0
		for ((i=0; i<$nd; i++)) 
		do
			d=${n:$i:1}
			#echo $d
			let s=s+d**nd
			#echo $s
		done
		if (( n == s))
		then
			echo "true"
			return 0
		else
			echo "false"
			return 1
		fi
		
	  else
          	echo "Usage: armstrong_numbers.sh <number>"
          	return 1
          fi

  fi
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if armstrong_numbers "$@"
then
        exit 0
        echo "good exit"
else
        exit 1
        echo "bad exit"
fi

