module two_fer
  implicit none

contains

  function twoFer(name) result(phrase)
    character(*), intent(in), optional :: name
    character(:), allocatable :: phrase

    if (trim(name) == "") then
            phrase = "One for you, one for me."
    else
            phrase = "One for " // name // ", one for me."        
    end if        
  end function twoFer

end module two_fer
