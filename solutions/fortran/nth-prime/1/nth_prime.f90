module nth_prime
  implicit none
contains

  ! get nth prime
  integer function prime(n)
    integer, intent(in) :: n
    integer, dimension(11000) :: primes 
    integer :: pl, num, i
    prime = -1
    if (n == 0) then
      prime = -1
      return
    end if
    if (n == 1) then
      prime = 2
      return
    end if
    num = 3
    pl = 1
    primes(1) = 2
    do while (pl < n)
      i=1
      do while (i<=pl)
        if (mod(num,primes(i)) == 0) then
          exit
        end if
        i=i+1
      end do
      if (i>pl) then        
        pl=pl+1
        primes(pl) = num
      end if
      num=num+1
    end do
    prime = primes(pl)
    return
  end function

end module
