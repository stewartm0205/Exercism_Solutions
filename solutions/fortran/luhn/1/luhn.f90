module luhn
  implicit none

contains

  function validate(num) result(valid)
    character(*), intent(in) :: num
    logical :: valid
    integer :: sum
    character(len=len(num)) :: stnum
    integer :: d
    integer :: i
    integer :: stat
    character(2) digit
    valid = .FALSE.
    !print *, "num=", num 
    if (len(trim(num)) < 2) return
    stnum = ''
    do i = 1,len(num)
        !print *, "num(i,i)=", num(i:i)
        if (num(i:i) /= ' ') stnum = trim(stnum) // num(i:i)        
        !print *, "i=", i, ", stnum=", stnum 
    end do
    !print *, "stnum=", stnum, ",len(stnum)=", len(stnum),",iachar(stnum(len(stnum):len(stnum))",iachar(stnum(len(stnum):len(stnum)))
    if (len(trim(stnum)) < 2) return
    do i = 1, len(trim(stnum))
      !print *,"i=",i,",stnum(i:i)=",stnum(i:i),",iachar=",iachar(stnum(i:i))," ",stnum(i:i)<'0'," ",stnum(i:i)>'9'
      if(trim(stnum(i:i)) < '0' .OR. trim(stnum(i:i)) > '9') return 
    end do
    do i = len(trim(stnum))-1,1,-2
        digit = stnum(i:i)//" "
        !print *, "digit=", digit
        read(digit,*,IOSTAT=stat) d
        !print *,"1 d=",d
        d = 2 * d 
        if ( d > 9) d = d - 9
        write(stnum(i:i),"(I1)") d 
    end do    
    !print *, "mod stnum=", stnum 
    sum = 0
    do i = 1,len(trim(stnum))
        digit = stnum(i:i)//" "
        read(digit,*,IOSTAT=stat) d
        !print *,"2 d=",d
        sum = sum + d
    end do
    !print *,"sum=", sum
    if (mod(sum,10) == 0) valid = .TRUE.    
  end function validate

end module luhn
