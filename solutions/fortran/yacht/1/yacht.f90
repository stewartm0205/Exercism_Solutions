
module yacht
  implicit none

  ! | Ones | 1 × number of ones | Any combination	| 1 1 1 4 5 scores 3 |
  ! | Twos | 2 × number of twos | Any combination | 2 2 3 4 5 scores 4 |
  ! | Threes | 3 × number of threes | Any combination | 3 3 3 3 3 scores 15 |
  ! | Fours | 4 × number of fours | Any combination | 1 2 3 3 5 scores 0 |
  ! | Fives | 5 × number of fives| Any combination | 5 1 5 2 5 scores 15 |
  ! | Sixes | 6 × number of sixes | Any combination | 2 3 4 5 6 scores 6 |
  ! | Full House | Total of the dice | Three of one number and two of another | 3 3 3 5 5 scores 19 |
  ! | Four of a Kind | Total of the four dice | At least four dice showing the same face | 4 4 4 4 6 scores 16 |
  ! | Little Straight |  30 points | 1-2-3-4-5 | 1 2 3 4 5 scores 30 |
  ! | Big Straight | 30 points | 2-3-4-5-6 | 2 3 4 5 6 scores 30 |
  ! | Choice | Sum of the dice | Any combination | 2 3 3 4 6 scores 18 |
  ! | Yacht | 50 points | All five dice showing the same face | 4 4 4 4 4 scores 50 |


contains

  integer function score(dice, yacht_type)
    integer, dimension(5), intent(in) :: dice
    character(len=*), intent(in) :: yacht_type
    integer :: i, j
    integer, dimension(6) :: dc
    score=0
    dc(:)=0
    do i = 1, 5
        select case(dice(i))
                case(1) 
                        dc(1) = dc(1) + 1
                case(2) 
                        dc(2) = dc(2) + 1
                case(3) 
                        dc(3) = dc(3) + 1
                case(4) 
                        dc(4) = dc(4) + 1
                case(5) 
                        dc(5) = dc(5) + 1
                case(6) 
                        dc(6) = dc(6) + 1
        end select                 

    end do
    !print *, "dc(*)", dc
    !print *, "yacht_type=", yacht_type
    select case (yacht_type)
        case("ones") 
                score = dc(1)
        case("twos") 
                score = dc(2) * 2
        case("threes") 
                score = dc(3) * 3
        case("fours") 
                score = dc(4) * 4
        case("fives") 
                score = dc(5) * 5
        case("sixes") 
                score = dc(6) * 6
        case("yacht")
                do i = 1,6 
                        if (dc(i) == 5) score = 50
                end do        
        case("full house")
                do i = 1, 6
                        if (dc(i) == 3) then
                                do j = 1, 6
                                        if (dc(j) == 2) then
                                                score = 3 * i + 2 * j
                                                exit
                                        end if
                                end do
                        end if                        
                end do        
        case("four of a kind")
                !print *, dice
                do i = 1, 6
                        !print *,i,dc(i)
                        if (dc(i) >= 4) score = i * 4
                end do        
                !print *, score
        case("little straight")
                if (dc(1) == 1 .and. dc(2) == 1 .and. dc(3) == 1 .and. dc(4) == 1 .and. dc(5) == 1) score=30
        case("big straight")
                if (dc(2) == 1 .and. dc(3) == 1 .and. dc(4) == 1 .and. dc(5) == 1 .and. dc(6) == 1) score=30
        case("choice")
                score=dc(1)+dc(2)*2+dc(3)*3+dc(4)*4+dc(5)*5+dc(6)*6
        case default 
                print *, "not impl"        
    end select
  end function


end module
