
module acronym
  implicit none
contains

  function abbreviate(s)
    character(len=*), intent(in) :: s
    character(len=len_trim(s)) :: abbreviate
    character(len=len_trim(s)) :: st
    integer :: i, j, code
    !print *, "s=", s
    st=s
    abbreviate=""
    i=1
    j = 1
    do while (i>0 .and. len(trim(st)) > 0)
       code = iachar(st(1:1))
       if (code >= 97) then
           abbreviate = trim(abbreviate) // achar(code - 32) 
       else    
           abbreviate = trim(abbreviate) // st(1:1)
       end if    
       !print *, "abb=",abbreviate 
       i = scan(st, " -_")
       do while (index(" -_", st(i+1:i+1)) > 0)
           i=i+1
       end do    
       st = st(i+1:)
       !print *, "st=", st
       j = j+1
       if (j>20) exit
    end do 
  end function

end module
