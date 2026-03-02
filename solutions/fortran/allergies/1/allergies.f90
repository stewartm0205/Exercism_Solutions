
module allergies
  implicit none

contains

  logical function allergicTo(allergy_str, allergy_key)
    character(len=*), intent(in) :: allergy_str
    integer, intent(in) :: allergy_key
    integer :: i, r, k
    character(len=15), dimension(8) :: allergies
    allergies = (/ "eggs        ", "peanuts     ", "shellfish   ", "strawberries", "tomatoes    ", &
            "chocolate   ", "pollen      ", "cats        " /)
    !print *, "allergicTo ", allergy_str, allergy_key
    allergicTo = .false.
    k = allergy_key 
    do i = 1,8 
        r = mod (k, 2)
        !print *, "r=",r
        k = k / 2
        !print *, trim(allergy_str), " ", trim(allergies(i)), " ",trim(allergy_str) == trim(allergies(i))
        if (r > 0 .and. (trim(allergy_str) == trim(allergies(i)))) allergicTo = .true.
    end do
  end function


  function allergicList(allergy_key)
    integer, intent(in) :: allergy_key
    character(len=100) :: allergicList
    integer :: i, r, k
    character(len=15), dimension(8) :: allergies
    !print *, "allergicList ", allergy_key
    allergicList = ''
    allergies = (/ "eggs        ", "peanuts     ", "shellfish   ", "strawberries", "tomatoes    ", &
            "chocolate   ", "pollen      ", "cats        " /)
    k = allergy_key
    do i = 1,8
        r = mod (k, 2)
        k = k / 2
        if (r > 0) then
                if (allergicList == '') then 
                        allergicList = allergies(i)
                else 
                        allergicList = trim(allergicList) // ' ' // allergies(i) 
                end if        
        end if                
    end do
  end function



end module
