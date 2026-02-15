#!/usr/bin/env bash
# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

bob() {
  if [ $# -ne 1 ]
  then
    echo "Usage: bob.sh <sentence>"
    return 1
  fi
  sentence=$1
  echo $sentence

  pat="^.*[A-Z]+.*[^\\?] *$"
  if [[ $sentence == ${sentence^^} && $sentence =~ $pat ]] 
  then
    echo "Whoa, chill out!"; return 0
  fi

  pat="^.*[A-Z]+.*[^\\?] *$"
  if [[ $sentence == ${sentence^^} && $sentence =~ $pat ]] 
  then
    echo "Whoa, chill out!"; return 0
  fi

  pat="^.*[A-Z]+.*\\? *$" 
  if [[ $sentence == ${sentence^^} && $sentence =~ $pat ]] 
  then
    echo "Calm down, I know what I'm doing!"; return 0
  fi
  
  pat="^.*\\? *$" 
  if [[ $sentence =~ $pat ]]
  then
    echo "Sure." ;return 0
  fi

  pat="^[\\t\\r\\n ]*$"
  if [[ $sentence =~ $pat ]]
  then
    echo "Fine. Be that way!"; return 0
  fi

  echo "Whatever."
  return 0
 
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if bob "$@"
then
        exit 0
else
        exit 1
fi

