#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

nucleotide_count() {

  if [ $# -ne 1 ]
  then
    echo "Usage: nucleotide_count.sh <dna>"
    return 1
  fi

  if ! [[ $1 =~ ^[ACGT]*$ ]]
  then
    echo "Invalid nucleotide in strand"
    return 1
  fi

  dna=$1
  ac=0
  cc=0
  gc=0
  tc=0
  for i in $(seq 1 ${#dna})
  do
    n=${dna:i-1:1}
    case $n in
    A)
       ((ac=ac+1))
       ;;
    C)
       ((cc=cc+1))
       ;;
    G)
       ((gc=gc+1))
       ;;
    T)
       ((tc=tc+1))
       ;;
    esac
  done
  echo -e "A: $ac\nC: $cc\nG: $gc\nT: $tc"
  return 0
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if nucleotide_count "$@"
then
  exit 0
else
  exit 1
fi

