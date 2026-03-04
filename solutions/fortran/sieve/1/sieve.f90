module sieve
  implicit none

contains

  function primes(limit) result(array)
    integer, intent(in) :: limit
    integer, allocatable:: array(:)
    integer, dimension(1000):: temp
    integer :: i, j, n
    !print *, "limit=",limit 
    if (limit<2) then
        allocate(array(0))
        return
    end if    
    temp(:) = 0
    temp(1) = 2
    n = 3
    i = 1 
    do while (n <= limit)
      do j=1,i
        if (mod(n,temp(j)) == 0) exit
      end do
      if (j > i) then
         !print *, "i=",i, ",n=",n
         i = i + 1
         temp(i) = n  
      end if   
      n = n + 2
    end do
    allocate(array(i))
    array(1:i) = temp(1:i)
    !print *, "array=",array 
  end function primes

end module sieve
