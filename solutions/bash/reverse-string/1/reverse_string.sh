#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

reverse_string.sh() {
  if [ $# -lt 1 ]
  then
          echo "Usage: reverse_string.sh <string>"
          return 1
  elif [ $# -gt 1 ]
  then
          echo "Usage: reverse_string.sh <string>"
          return 1
  else
	  s=$1
          nc=${#s}
          #echo $nc
          rs=""
          for ((i=0; i<$nc; i++))
          do
               rs=${s:$i:1}${rs}
               #echo $rs
          done
	  echo $rs
          return 0

  fi
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if reverse_string.sh "$@"
then
        exit 0
        echo "good exit"
else
        exit 1
        echo "bad exit"
fi

