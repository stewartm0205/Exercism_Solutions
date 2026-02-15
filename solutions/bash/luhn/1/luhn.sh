#!/usr/bin/env bash 
# This option will make the script exit when there is an error
set -o errexit
# This option will make the script exit when it tries to use an unset variable
set -o nounset

luhn() {
  if [ $# -ne 1 ]
  then
    echo "Usage: $0 <numbers>"; return 1
  fi

  # if not digits or blank then error
  pat="^[0-9 ]+$"
  if ! [[ $1 =~ $pat ]]
  then
    echo "false"; return 0
  fi

  numbers=`echo $1 | sed 's/\s*//g'`

  nd=${#numbers}
  if [[ $nd == 1 ]]
  then
    echo "false"; return 0
  fi

  s=0
  ri=0
  for ((i=nd-1; i>=0; i--))
  do
    #echo "i=$i"
    ((ri++))
    #echo "ri=$ri"
    d=${numbers:$i:1}
    #echo "d=$d"
    if (( ri%2==0 )) 
    then 
      #echo "double"
      ((d=d*2)) 
      if ((d>9))
      then
        ((d=d-9))
      fi
    fi
    #echo "d=$d"
    ((s=s+d)) 
  done
  #echo $s
  if (( s%10==0 ))
  then 
    echo "true"; return 0
  fi

  echo "false" ; return 0
 
}
# Calls the main function passing all the arguments to it via '$@'
# The argument is in quotes to prevent whitespace issues
if luhn "$@"
then
        exit 0
else
        exit 1
fi

