module hamming
  implicit none
contains

  function compute(strand1, strand2, distance)
      character(len=20) :: strand1
      character(len=20) ::  strand2
      character(len=20) ::  strand
      integer,intent(out) :: distance
      integer :: i, j
      logical :: compute
      strand=strand2
      if (len_trim(strand1) /= len_trim(strand)) then
        compute = .false.
        return
      end if
      distance = 0
      do i=1,len(strand1)
        if (strand1(i:i) == strand(i,i)) then
          distance = distance + 1
        end if
      end do
      return 

  end function compute

end module hamming
