module darts
  implicit none

contains

  function score(x, y) result(points)
    real, intent(in):: x, y
    real :: r
    integer :: points
    r = sqrt((x * x) + (y * y))
    !print *, x, y, r
    if (r > 10) then 
            points = 0   
    else if (r > 5) then
            points = 1
    else if (r > 1) then
            points = 5
    else
            points = 10
    end if
    !print *, points
  end function score

end module darts
