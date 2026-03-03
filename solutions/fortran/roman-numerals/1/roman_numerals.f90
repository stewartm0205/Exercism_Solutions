module roman_numerals
  implicit none

contains

  function roman(num) result(s)
    integer, value :: num
    character(15) :: s
    integer, dimension(13) :: an = (/ 1000,900,500,400,100,90,50,40,10,9,5,4,1 /)
    character(2), dimension(13) :: rn = (/ "M ","CM","D ","CD","C ","XC","L ","XL","X ","IX","V ","IV","I " /)
    integer :: n, j
    s = ""
    n = num
    !print *, "num=", n
    j = 1
    do while (n > 0 .and. j <14) 
        if (an(j)<=n) then 
                s = trim(s) // rn(j)
                n = n - an(j)
        else
                j = j + 1
        end if
        !print *,"j=",j,"n=",n,"s=", s
    end do        
    !print *,"s=", s


  end function roman

end module roman_numerals
