module difference_of_squares
  implicit none
contains
  integer function square_of_sum(n)
  integer :: n, i
  square_of_sum=0
  do i = 1,n 
    square_of_sum=square_of_sum+i
  end do
  square_of_sum = square_of_sum * square_of_sum
  return
  end function square_of_sum

  integer function sum_of_squares(n)
  integer :: n, i
  sum_of_squares=0
  do i = 1,n 
    sum_of_squares=sum_of_squares+i*i
  end do
  return
  end function sum_of_squares

  integer function difference(n)
    integer :: n
    difference = square_of_sum(n) - sum_of_squares(n)
    return
  end function difference

end module difference_of_squares
