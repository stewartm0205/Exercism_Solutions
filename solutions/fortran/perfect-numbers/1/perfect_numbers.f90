
module perfect_numbers
  implicit none

contains

  character(len=9) function classify(num)
    integer, intent(in) :: num
    integer asum, i
    if (num < 1) then
      classify = "ERROR"
      return
    end if  
    if (num == 1) then
      classify = "deficient"
      return
    end if  
    asum=1
    do i = 2,num-1
      if (mod(num,i) == 0) then
        asum=asum+i
      end if
    end do
    if (asum == num) then
      classify = "perfect"
    else if (asum > num) then
      classify = "abundant"
    else 
      classify = "deficient"
    end if
    return
  end function

end module
