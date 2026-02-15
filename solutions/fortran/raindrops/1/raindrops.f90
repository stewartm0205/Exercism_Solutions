module raindrops
  implicit none
contains

  function convert(i)
    integer :: i
    character(len=:), allocatable :: convert
    convert=""
    if (mod(i,3) == 0) then
      convert = convert // "Pling"
    end if
    if (mod(i,5) == 0) then
      convert = convert // "Plang"
    end if
    if (mod(i,7) == 0) then
      convert = convert // "Plong"
    end if
    print *, "convert=", convert
    if (trim(convert) == "") then
      write(convert,'(i10)') i;
      convert=trim(convert)
    end if
    return

  end function convert

end module raindrops
