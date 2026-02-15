module bob
  implicit none
contains

  function hey(statement)
    character(100) :: hey
    character(len=*), intent(in) :: statement
    if (index(statement,"?")>0 .and. &
        statement == toUpper(statement) .and. &
        hasLetter(statement)) then
      hey = "Calm down, I know what I'm doing!" 
    else if (index(trim(statement),"?")== &
               len_trim(statement) .and. & 
               len_trim(statement)>0) then
      hey="Sure."
    else if (statement == toUpper(statement) .and. &
             hasLetter(statement)) then
      hey="Whoa, chill out!" 
    else if (len_trim(statement)==0) then
      hey = "Fine. Be that way!"
    else 
      hey = "Whatever."
    end if 
    return
  end function hey

  function toUpper(lc)
    character(len=*), intent(in) :: lc
    character(100) :: toUpper
    integer :: i 
    toUpper=""
    do i=1,len(lc)
      if (lc(i:i)>='a' .and. lc(i:i)<='z') then
        toUpper(i:i) = achar(iachar(lc(i:i)) - 32)
      else
        toUpper(i:i) = lc(i:i)
      end if
    end do
    return
  end function toUpper
  
  logical function hasLetter(s)
    character(len=*), intent(in) :: s
    integer :: i 
    do i=1,len(s)
      if (s(i:i)>='a' .and. s(i:i)<='z' .or. &
          s(i:i)>='A' .and. s(i:i)<='Z' ) then
        hasLetter=.true.
        return
      end if
    end do
    hasLetter=.false.
    return
  end function hasLetter
end module bob
