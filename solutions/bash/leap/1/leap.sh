#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

leap() {
  if [ $# -lt 1 ]
  then
          echo "Usage: leap.sh <year>"
          return 1
  elif [ $# -gt 1 ]
  then
          echo "Usage: leap.sh <year>"
          return 1
  else
          y=$1 
	  if [[ $y =~ ^[0-9]+$ ]]
          then
	  	if [ $((y%400)) -eq 0 ]
	  	then
		  echo "true" 
	  	elif [ $((y%100)) -eq 0 ]
    	  	then
		  echo "false" 
	  	elif [ $((y%4)) -eq 0 ]
 	  	then
		  echo "true" 
          	else
		  echo "false" 
          	fi
          	return 0
	  else
          	echo "Usage: leap.sh <year>"
          	return 1
	  fi

  fi
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if leap "$@"
then
        exit 0
	echo "good exit"
else
        exit 1
	echo "bad exit"
fi

