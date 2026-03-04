module isogram
  implicit none

contains

  function isIsogram(phrase) result(no_repeats)
    character(len=*), intent(in) :: phrase
    logical :: no_repeats
    character(26) :: alphabet="abcdefghijklmnopqrstuvwxyz"
    character(26) :: capital= "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    integer, dimension(26) :: cc
    integer :: i, j

    !print *, phrase
    cc(:) = 0
    no_repeats = .true.
    do i = 1, len(trim(phrase))
       j = index(alphabet, phrase(i:i))
       if (j==0) j = index(capital, phrase(i:i))
       if (j>0) then
               cc(j) = cc(j) + 1
               if (cc(j) > 1) then
                      no_repeats = .false.
                      return
              end if       
       end if 
    end do

  end function isIsogram

end module isogram
