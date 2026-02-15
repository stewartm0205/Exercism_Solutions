
module triangle
  implicit none

  interface equilateral
    module procedure equilateral_real
    module procedure equilateral_int
  end interface

  interface scalene
    module procedure scalene_real
    module procedure scalene_int
  end interface

  interface isosceles
    module procedure isosceles_real
    module procedure isosceles_int
  end interface

 contains

  logical function equilateral_real(edges)
    real,dimension(3) :: edges
    equilateral_real = .false.
    if (edges(1)==0.0) then
      return
    end if
    if (edges(1)==edges(2) &
     .and. edges(2)==edges(3)) then
        equilateral_real = .true.
    end if
    return
  end function

  logical function equilateral_int(edges)
    integer,dimension(3) :: edges
    equilateral_int = .false.
    if (edges(1)==0) then
      return
    end if
    if (edges(1)==edges(2) &
    .and. edges(2)==edges(3)) then
       equilateral_int = .true.
    end if
    return
  end function

  logical function isosceles_real(edges)
    real,dimension(3) :: edges
    isosceles_real = .false.
    if (edges(1)>edges(2)+edges(3) .or. &
    edges(2)>edges(1)+edges(3) .or. &
    edges(3)>edges(1)+edges(2)) then
      return
    end if 
    if (edges(1)==edges(2) &
    .or. edges(2)==edges(3) &
    .or. edges(1)==edges(3)) then
      isosceles_real = .true.
    end if
    return
  end function

  logical function isosceles_int(edges)
    integer,dimension(3) :: edges
    isosceles_int = .false.
    if (edges(1)>edges(2)+edges(3) .or. &
    edges(2)>edges(1)+edges(3) .or. &
    edges(3)>edges(1)+edges(2)) then
      return
    end if 
    if (edges(1)==edges(2) &
    .or. edges(2)==edges(3) &
    .or. edges(1)==edges(3)) then
      isosceles_int = .true.
    end if
    return
  end function


  logical function scalene_real(edges)
    real,dimension(3) :: edges
    scalene_real = .false.
    if (edges(1)>edges(2)+edges(3) .or. &
        edges(2)>edges(1)+edges(3) .or. &
        edges(3)>edges(1)+edges(2)) then
          return
    end if      
    if (edges(1)/=edges(2) &
    .and. edges(2)/=edges(3) &
    .and. edges(1)/=edges(3)) then
      scalene_real = .true.
    end if
    return
  end function

  logical function scalene_int(edges)
    integer,dimension(3) :: edges
    scalene_int = .false.
    if (edges(1)>edges(2)+edges(3) .or. &
    edges(2)>edges(1)+edges(3) .or. &
    edges(3)>edges(1)+edges(2)) then
      return
    end if  
    if (edges(1)/=edges(2) &
    .and. edges(2)/=edges(3) &
    .and. edges(1)/=edges(3)) then
      scalene_int = .true.
    end if
    return
  end function

end module
