
module high_scores
  implicit none
contains

function scores(score_list) result(scores_out)
  integer, dimension(:), intent(in) :: score_list
  integer  :: scores_out(size(score_list))
  scores_out = score_list      
end function
  
function latest(score_list) result(last)
  integer, dimension(:) :: score_list
  integer :: last
  last = score_list(size(score_list,1))
end function

function personalBest(score_list) result(best)
  integer, dimension(:) :: score_list
  integer :: best
  integer :: i

  best = score_list(1)
  do i = 2,size(score_list,1)
        if (best < score_list(I)) best = score_list(i)
  end do
end function
  
function personalTopThree(score_list) result(topthree)
  integer, dimension(:) :: score_list
  integer, dimension(size(score_list)) :: scores 
  integer, dimension(3) :: topthree
  integer :: i, j, bi
  !print *, "size=", size(score_list)," score_list=", score_list 
  scores = score_list
  topthree(:) = 0
  do j = 1,3
        topthree(j) = scores(1)
        bi=1
        do i = 2,size(scores,1)
                if (topthree(j) < scores(i)) then
                       topthree(j) = scores(i)
                       bi = i
                end if       
        end do
        !print *, bi
        scores(bi) = 0
  end do      

end function

end module
