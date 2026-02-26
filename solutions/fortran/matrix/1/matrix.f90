
module matrix
  implicit none

contains

  function row(matrix, dims, i) result(r)
    integer, dimension(2), intent(in) :: dims
    !! Matrix dimensions (nrows, ncols)
    character(len=*), dimension(dims(1)), intent(in) :: matrix
    !! Matrix as a 1-d array of strings
    integer, intent(in) :: i
    !! Row index
    integer, dimension(dims(2)) :: r
    integer :: stat
    r(:) = 0
    read(matrix(i), *, IOSTAT=stat) r
  end function

  function column(matrix, dims, j) result(c)
    integer, dimension(2), intent(in) :: dims
    !! Matrix dimensions (nrows, ncols)
    character(len=*), dimension(dims(1)), intent(in) :: matrix
    !! Matrix as a 1-d array of strings
    integer, intent(in) :: j
    !! Column index
    integer, dimension(dims(1)) :: c
    integer, dimension(dims(2)) :: r
    integer :: k
    integer :: stat
    c(:) = 0
    do k=1,dims(1)
      read(matrix(k),*,IOSTAT=stat) r
      c(k) = r(j)
    end do
  end function

end module
