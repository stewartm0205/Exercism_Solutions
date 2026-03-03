module sum_of_multiples
  implicit none

contains

  function sum_multiples(factors, limit) result(res)
    integer, intent(in) :: factors(:), limit
    integer :: res
    integer, dimension(10000) :: all
    integer :: i, f, j, k

    !print *, "factors=", factors, " limit=", limit
    res = 0
    j = 0
    do i = 1, size(factors)
        f=factors(i)
        do while (f> 0 .and. f < limit)
                do k = 1,j
                        if (f == all(k)) exit  
                end do
                if (k>j) then
                        j=j+1
                        all(j)=f
                end if
                f = f + factors(i)
        end do        
    end do   
    do i = 1,j
        res = res + all(i)
    end do

  end function sum_multiples


end module sum_of_multiples
