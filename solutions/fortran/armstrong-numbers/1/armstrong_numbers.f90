
module armstrong_numbers
  implicit none
contains

  logical function isArmstrongNumber(i)
    integer, intent(in) :: i
    integer :: s, j, d, l
    character(10) :: digits
    isArmstrongNumber = .false.
    write(digits,"(i10)") i
    digits=trim(adjustl(digits))
    l=len_trim(digits)
    s=0
    do j=1,len_trim(digits)
      read(digits(j:j),*) d
      s=s+d**l
    end do
    if (s==i) then 
      isArmstrongNumber = .true.
    end if
    return
  end function

end module
