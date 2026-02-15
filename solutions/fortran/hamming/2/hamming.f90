module hamming
  implicit none
contains

  function compute(strand1, strand2, distance)
      character(len=*) :: strand1
      character(len=*) ::  strand2
      integer,intent(out) :: distance
      integer :: i
      logical :: compute
      distance = 0
      if (len(strand1(:)) /= len(strand2(:))) then
        compute = .false.
        return
      end if
      compute = .true.
      do i=1,len(strand1)
        if (strand1(i:i) /= strand2(i:i)) then
          distance = distance + 1
        end if
      end do
      return 

  end function compute

end module hamming
