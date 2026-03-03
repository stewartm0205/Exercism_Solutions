module reverse_string
  implicit none
contains

  function reverse(input) result(reversed)
    character(*), intent(in) :: input
    character(len=len(input)) :: reversed
    integer :: i, j

    reversed = ""
    !print *,"input=",input, " len=", len(input)
    j=1
    do i = len(input),1,-1
        reversed(j:j) = input(i:i)
        !print *, "rev=", reversed
        j = j + 1
    end do


  end function

end module
