module pangram
  implicit none
contains

  logical function is_pangram(sentence)
    character(*) :: sentence
    character(26) :: lc,uc
    integer :: i
    lc="abcdefghijklmnopqrstuvwxyz"
    uc="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    do i=1,len(sentence(:))
      if (index(lc,sentence(i:i))>0) then
        lc(index(lc,sentence(i:i)): &
              index(lc,sentence(i:i)))=" "
      end if
      if (index(uc,sentence(i:i))>0) then
        lc(index(uc,sentence(i:i)): &
              index(uc,sentence(i:i)))=" "
      end if
    end do
    if (len_trim(lc)==0) then
      is_pangram=.true.
      return
    end if
    is_pangram=.false.
    return  
   end function is_pangram

end module pangram
