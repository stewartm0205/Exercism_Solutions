module protein_translation
  implicit none

contains

  function proteins(rna) result(names)
    character(len=*), intent(in) :: rna
    character(len=13), allocatable :: names(:)
    character(len=13), dimension(20) :: tnames
    integer :: i,j
    !print *, "rna=", rna
    tnames(:) = ""
    j = 0
    do i = 1,len(trim(rna)),3
        j = j + 1
        select case(rna(i:i+2))
           case("AUG")
                  tnames(j:j) = "Methionine" 
           case("UUU","UUC")
                  tnames(j:j) = "Phenylalanine"
           case("UUA", "UUG")
                 tnames(j:j) =  "Leucine"
           case("UCU", "UCC", "UCA", "UCG")
                 tnames(j:j) =   "Serine"
            case("UAU", "UAC")
                 tnames(j:j) =   "Tyrosine"
            case("UGU", "UGC")
                 tnames(j:j) =   "Cysteine"
            case("UGG")
                 tnames(j:j) =   "Tryptophan"
            case("UAA", "UAG", "UGA")
                    j = j - 1
                    exit 
        end select

    end do    
    !print *, "j=", j
    !print *, "tnames=", tnames
    allocate(names(j))
    if (j>0) names(1:j) = tnames(1:j)
  end function proteins

end module protein_translation

