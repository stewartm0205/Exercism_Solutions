#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

error_handling() {
  if [ $# -lt 1 ]
  then
          echo "Usage: ./error_handling <greetee>"
          return 1
  elif [ $# -gt 1 ]
  then
          echo "Usage: ./error_handling <greetee>"
          return 1
  else
          echo "Hello, $1" 
          return 0
  fi
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if error_handling "$@"
then 
	exit 0
else
	exit 1
fi
