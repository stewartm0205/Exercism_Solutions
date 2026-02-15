
module collatz_conjecture
  implicit none
contains

  integer function steps(i)
    integer, intent(in) :: i
    integer :: num
    num = i
    steps = -1
    do while (num>=1)
      steps = steps + 1  
      if (num==1) then
        exit
      end if
      if (mod(num,2) == 0) then
        num = num / 2
      else
        num = 3 * num + 1
      end if
     
    end do  
    return
  end function

end module
