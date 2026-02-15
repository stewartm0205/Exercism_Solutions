#!/usr/bin/env bash

# This is a bash script template in order to help you quick start any script.
# It contains some sensible defaults, you can learn more by visiting:
# https://google.github.io/styleguide/shell.xml

# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

nucleotide_count() {
  if [ $# -lt 1 ]
  then
          echo "Usage: nucleotide_count.sh <dna>"
          return 1
  elif [ $# -gt 1 ]
  then
          echo "Usage: nucleotide_count.sh <dna>"
          return 1
  else
          dna=$1
	  ac=0
	  cc=0
	  gc=0
	  tc=0
          if [[ $dna =~ ^[ACGT]*$ ]]
          then
		for i in $(seq 1 ${#dna})
                do
                	n=${dna:i-1:1}
                	#echo $n
 			if [ $n == "A" ]
                	then
                           let ac=ac+1	
                	elif [ $n == "C" ]
                	then
                           let cc=cc+1	
                	elif [ $n == "G" ]
                	then
                           let gc=gc+1	
		   	else
                           let tc=tc+1	
			fi
		done
		echo -e "A: $ac\nC: $cc\nG: $gc\nT: $tc"
                return 0
          else
                echo "Invalid nucleotide in strand"
                return 1
          fi

  fi
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if nucleotide_count "$@"
then
        exit 0
        echo "good exit"
else
        exit 1
        echo "bad exit"
fi

