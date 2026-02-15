
module collatz_conjecture
  implicit none
contains

  integer function steps(i)
    integer :: i
    steps = 0
    do while (i>1)
      if (mod(i,2) == 0) then
        i = i / 2
      else
        i = 3 * i + 1
      end if
      steps = steps + 1   
    end do  
    return
  end function

end module
