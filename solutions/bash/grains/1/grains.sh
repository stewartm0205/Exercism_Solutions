#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

grains() {
  n=$1
  g=1
  if [ $n -lt 1 ]
  then
	  echo "Error: invalid input"
	  exit 1
  fi
  if [ $n -gt 64 ]
  then
	  echo "Error: invalid input"
	  exit 1
  fi
  if [ $n -eq 1 ]
  then
	  echo $g
	  exit
  fi
  for i in `seq 2 $n`
  do
	  g=$(echo "$g*2" | bc)
  done
  echo "$g" 
}

# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if [ $1 == "total" ]
then
	tg=0
	for i in `seq 1 64`
	do
		g=`grains $i`
		tg=$(echo "$tg+$g"|bc)
	done
	echo "$tg"
else
	grains "$@"
fi
exit 0

