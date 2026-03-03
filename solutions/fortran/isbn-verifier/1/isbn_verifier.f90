module isbn_verifier
  implicit none

contains

  function isValid(isbn) result(valid)
    character(*), intent(in) :: isbn
    logical :: valid
    character(12) :: vchr = "-0123456789X"
    character(20) :: nums
    integer :: i, sum

    !print *, "isbn=", isbn
    valid = .false.
    
    sum = 0
    nums = ""
    if (index(isbn, "X") > 0 .and. index(isbn, "X") /= len(isbn)) return 
    do i = 1, len(isbn)
        if (index(vchr, isbn(i:i)) == 0) return
        if (isbn(i:i) /= '-') then
                nums = trim(nums) // isbn(i:i) 
        end if
    end do    
    !print *, "nums=", nums
    if (len(trim(nums)) /= 10) return
    do i = 1, len(trim(nums))
                sum = sum + ((11 - i) * (index(vchr, nums(i:i)) - 2))
                !print *, "nums(i,i)=", nums(i:i), " n=", (index(vchr, nums(i:i)) - 2)
    end do

    if (mod(sum, 11) == 0) valid = .true.

  end function isValid

end module isbn_verifier
