
module grains

  implicit none

contains

  double precision function square(n)
    integer :: n, i
    if (n <= 0 .or. n >64) then
      square = -1.d0
      return
    end if
    square = 1.d0
    do i = 2,n 
      square=square*2
    end do
    return
  end function

  double precision function total()
  integer :: i
    total = 0.d0
    do i = 1,64
      total=total + square(i)
    end do
    return
  end function

end module
