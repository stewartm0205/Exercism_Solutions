
module rational_numbers
  implicit none
contains

  function add(r1,r2)
    integer,dimension(2) :: add, r1,r2
    add(1)=r1(1)*r2(2) + r2(1)*r1(2)
    add(2)=r1(2)*r2(2)
    add=reduce(add)
    return
  end function

  function sub(r1,r2)
    integer,dimension(2) :: sub, r1,r2
    sub(1)=r1(1)*r2(2) - r2(1)*r1(2)
    sub(2)=r1(2)*r2(2)
    sub=reduce(sub)
    return
  end function

  function mul(r1,r2)
    integer,dimension(2) :: mul, r1,r2
    mul(1)=r1(1)*r2(1)
    mul(2)=r1(2)*r2(2)
    mul=reduce(mul)
    return
  end function

  function div(r1,r2)
    integer,dimension(2) :: div, r1,r2
    div(1)=r1(1) * r2(2)
    div(2)=r1(2) * r2(1)
    div=reduce(div)
    return
  end function

  function rational_abs(r1)
    integer,dimension(2) :: rational_abs, r1
    rational_abs(1) = abs(r1(1)) 
    rational_abs(2) = abs(r1(2))
    return 
  end function

  function rational_to_pow(r1, ex)
    integer,dimension(2) :: rational_to_pow, r1
    integer :: ex
    if (ex>=0) then
      rational_to_pow(1)=r1(1)**ex
      rational_to_pow(2)=r1(2)**ex
    else
      rational_to_pow(1)=r1(2)**ex
      rational_to_pow(2)=r1(1)**ex
    end if
    return
  end function

  function real_to_rational_pow(ex,r1)
    integer,dimension(2) ::  r1
    real :: real_to_rational_pow,ex
    real_to_rational_pow = ex**r1(1)
    real_to_rational_pow = real_to_rational_pow**(1.0/r1(2))
    return
  end function

  function reduce(r1)
    integer,dimension(2) :: reduce, r1
    reduce(1)=r1(1)/igcd(r1(1),r1(2))
    reduce(2)=r1(2)/igcd(r1(1),r1(2))
    if (reduce(1)==0) then
      reduce(2)=1
    end if 
    if (reduce(2)<0) then
      reduce(1)=-reduce(1)
      reduce(2)=-reduce(2)
    end if
    return
  end function

  integer function igcd(m,n)
  integer,intent(in)  :: m, n
  integer            :: irest,ifirst
      ifirst=iabs(m)
      igcd=iabs(n)
      if(igcd.eq.0)then
      igcd=ifirst
      else
        do
            irest = mod(ifirst,igcd)
            if(irest == 0)  exit
            ifirst = igcd
            igcd = irest
        enddo
        igcd= iabs(igcd)
      endif
  end function igcd

end module
