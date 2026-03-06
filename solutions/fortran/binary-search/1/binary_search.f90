module binary_search
  implicit none
contains

  function find(array, val) result(idx)
    integer, dimension(:), intent(in) :: array
    integer, intent(in) :: val
    integer :: idx
    integer :: lb,hb, mp

    !print *, "val=", val, "array=", array
    idx = -1
    lb = 1
    hb = size(array)
    do while (.true.) 
        mp = lb + (hb - lb)/2
        !print *,"lb,mp,hb=", lb, mp, hb
        if (mp == 0 .or. hb == 0) exit
        if (val == array(hb)) then
                idx=hb
                exit
        else if (val == array(lb)) then
                idx=lb
                exit
        else if (val == array(mp)) then
                idx=mp
                exit
        else if (val > array(mp)) then
                lb = mp
        else 
                hb = mp        
        end if        
        if (lb == hb) then
                idx = -1
                exit
        end if
        if ((hb - lb) < 2) exit
    end do        

    !print *,"idx=",idx

  end function

end module
