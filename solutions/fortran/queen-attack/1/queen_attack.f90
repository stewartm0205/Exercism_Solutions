
module queen_attack
  implicit none
contains

  logical function isValid(pos)
    integer, dimension(2) :: pos
    
    if (pos(1)<0 .or. pos(2)<0 .or.& 
        pos(1)>8 .or. pos(2)>8) then
      isValid = .false.
      return
    end if 
    isValid = .true.
    return
  end function

  logical function canAttack(white_pos, black_pos)
    integer, dimension(2) :: white_pos, black_pos
    
    if (white_pos(1)==black_pos(1) .or. &
        white_pos(2)==black_pos(2)) then
          canAttack = .true.
      return
    end if
    if (abs((white_pos(1)-black_pos(1))/ &
       (white_pos(2)-black_pos(2))) == 1) then
      canAttack = .true.
      return
    end if
    canAttack = .false.
    return
  end function

end module
