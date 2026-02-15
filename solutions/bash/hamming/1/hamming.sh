#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

hamming() {
  if [ $# -eq 2 ]
  then
	  dna1=$1
          dna2=$2
	  if [[ ${#dna1} == ${#dna2} ]]
  	  then
	  	dist=0
		for i in $(seq 1 ${#dna1})
                do
                	if [[ ${dna1:i-1:1} != ${dna2:i-1:1} ]]
                	then
                           let dist+=1	
			fi
		done
		echo $dist
                return 0
          else
                echo "left and right strands must be of equal length"
                return 1
          fi
  else
          echo "Usage: hamming.sh <strand1> <strand2>"
          return 1
  fi
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if hamming "$@"
then
        exit 0
else
        exit 1
fi

