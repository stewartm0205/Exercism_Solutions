#!/usr/bin/env bash

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

atbash_cipher.sh() {
  if [[ $# -ne 2 ]]
  then
    echo "Usage: $0 [encode|decode] <string>"
    return 1
  elif [[ $1 != "encode" && $1 != "decode" ]]
  then
    echo "Usage: $0 [encode|decode] <string>"
    return 1
  fi

	s=$2
  # convert to lowercase
  s=${s,,}
  nc=${#s}
  alpha="abcdefghijklmnopqrstuvwxyz0123456789"
  ralpha="zyxwvutsrqponmlkjihgfedcba0123456789"


  if [[ $1 == "encode" ]]
  then
    en=""
    i=0
    while [ $i -lt $nc ]
    do
      j=0
      while [ $j -lt 5 ] && [ $i -lt $nc ]
      do
        for ((n=0;n<35;n++))
        do
          if [[ ${s:$i:1} == ${alpha:$n:1} ]] 
          then
            en=$en${ralpha:$n:1}
            ((j=j+1))
            break
          fi
        done
        ((i=i+1))
      done
      en=$en" "
    done
	  echo $en
    return 0
  else
    de=""
    i=0
    while [ $i -lt $nc ]
    do
      j=0
      while [ $j -lt 5 ] && [ $i -lt $nc ]
      do
        for ((n=0;n<35;n++))
        do
          if [[ ${s:$i:1} == ${ralpha:$n:1} ]] 
          then
            de=$de${alpha:$n:1}
            break
          fi
        done
        ((i=i+1))
        ((j=j+1))
      done
    done
	  echo $de
    return 0
  fi
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if atbash_cipher.sh "$@"
then
        exit 0
else
        exit 1
fi

