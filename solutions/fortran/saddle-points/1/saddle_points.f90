module saddle_points
  implicit none

  type :: point_t
    integer :: row
    integer :: column
  end type point_t

contains

  function saddlePoints(matrix) result(points)
    integer, intent(in) :: matrix(:, :)
    type(point_t), allocatable :: points(:)
    type(point_t), dimension(10) :: tpoints
    integer :: i, j, k, m, mr, mi, np
    !print *,"=========== array ========="
    !do i =1,size(matrix,1)
    !  print *, matrix(i,:)
    !end do  
    np = 0 
    ! For all teh rows
    do i = 1,size(matrix,1)
       ! Find the largest value in a row
       mr = matrix(i,1)
       mi = 1
       do j = 2,size(matrix,2)
          if (matrix(i,j) > mr) then
             mi = j
             mr = matrix(i,j)
          end if   
       end do
       !print *, "mr=", mr
       ! Check if max row is min in column
       do k = 1, size(matrix, 1)
          !print *, "mi=",mi,"k=",k,",matrix(k,mi)=",matrix(k,mi)
          if (matrix(k,mi) < mr) exit
       end do
       !print *, "k=", k   
       if (k > size(matrix, 1)) then
           np = np + 1    
           !print *, "r=",i,",c=",mi  
           tpoints(np) = point_t(i , mi)
       end if
       ! Check if there are other columns with the same max row value
       !print *,"check the other cols if equal"
       do k=mi+1, size(matrix, 2)
          !print *, "second check, k=", k, ",matrix(i,k)=",matrix(i,k)
          if (matrix(i,k) == mr) then
             !check if min in column     
              do m = 1, size(matrix, 1)
                if (matrix(m,k)<mr) exit
              end do  
              if (m > size(matrix, 1)) then
                np  = np + 1    
                !print *, "r=",i,",c=",k  
                tpoints(np) = point_t(i , k)
              end if
          end if        
       end do   
    end do    
    allocate(points(np))
    points(1:np) = tpoints(1:np)
  end function saddlePoints

end module saddle_points
