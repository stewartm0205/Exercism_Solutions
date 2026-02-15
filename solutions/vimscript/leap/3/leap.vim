"
" This function takes a year and returns 1 if it's a leap year
" and 0 otherwise.
"
function! LeapYear(year) abort

  " 
  if year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) 
	  return 1
  else
	  return 0
  endif

endfunction
