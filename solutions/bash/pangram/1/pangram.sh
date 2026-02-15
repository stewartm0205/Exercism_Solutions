#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

pangram() {
  if [ $# -ne 1 ]
  then
    echo "Usage: pangram.sh <sentence>"
    return 1
  fi
  alphabet="abcdefghijklmnopqrstuvwxyz"
  sentence=${1,,}
  if (( ${#sentence} < 26 ))
 	then
    echo "false" 
    return 0
  fi
	for i in $(seq 1 ${#alphabet})
  do
   	if ! [[ $sentence =~ ^.*${alphabet:i-1:1}.*$ ]]
  	then
      echo "false" 
      return 0
		fi
	done
  echo "true" 
  return 0
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if pangram "$@"
then
        exit 0
else
        exit 1
fi

