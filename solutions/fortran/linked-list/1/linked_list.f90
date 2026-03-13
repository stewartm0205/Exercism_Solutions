module linked_list
  implicit none

  type :: list_t
    type(list_n), pointer :: first_node
  end type list_t

  type :: list_n
    integer :: val 
    type(list_n), pointer :: next_node
  end type list_n

contains

  function new() result(list)
    type(list_t), allocatable :: list
     
    allocate(list)
    nullify(list%first_node)
  end function new

  subroutine push(list, val)
    type(list_t), intent(inout) :: list
    integer, intent(in) :: val
    type(list_n) , target, allocatable :: list_node
    type(list_n) , pointer:: list_node_ptr
    type(list_n) , pointer:: tnode_ptr
    print *, "push"
    print *, "val=", val
    if (.not. associated(list%first_node)) then
        allocate(list_node)
        list_node%val = val
        nullify(list_node%next_node)
        list%first_node => list_node
        print *,"first node val=", list_node%val, ", associated(list%first_node)=",associated(list%first_node) 
    else      
       !ranverse the list to find the last node
       print *, "associated(list%first_node)=",associated(list%first_node) 
       tnode_ptr = list%first_node
       do while (associated(tnode_ptr%next_node))
         tnode_ptr = tnode_ptr%next_node
       end do

       allocate(list_node)
       tnode_ptr%next_node => list_node
       list_node%val = val
       nullify(list_node%next_node)
       print *, " rest of nodes, val=",list_node%val,",associated(list_node%next_node)=",associated(list_node%next_node) 
    end if
    print *, "end of push"

  end subroutine push

  function pop(list) result(val)
    type(list_t), intent(inout) :: list
    integer :: val
    type(list_n) , pointer:: tnode_ptr
    print *, "pop"
    print *, "associated(list%first_node)=",associated(list%first_node) 

    ! if list is empty just return
    if (.not. associated(list%first_node)) return
        
    ! if only a first node then delete it
    nullify(tnode_ptr)
    tnode_ptr => list%first_node
    print *, "val=",tnode_ptr%val,",associated(tnode_ptr%next_node)=",associated(tnode_ptr%next_node) 
    if (.not. associated(tnode_ptr%next_node)) then
            val = tnode_ptr%val
            print *, "2 val=", val
            deallocate(tnode_ptr)
            return
    end if
    print *,"shouldn't be here on first time"
    ! tranverse the list to find the last node
    print *, "2 val=",tnode_ptr%val, ", associated(tnode_ptr%next_node)=",associated(tnode_ptr%next_node) 
    do while (associated(tnode_ptr%next_node))
       tnode_ptr => tnode_ptr%next_node
       print *, "3 val=",tnode_ptr%val, ", associated(tnode_ptr%next_node)=",associated(tnode_ptr%next_node) 
    end do
    val = tnode_ptr%val
    deallocate(tnode_ptr)

  end function pop

  subroutine unshift(list, val)
    type(list_t), intent(inout) :: list
    integer, intent(in) :: val
    type(list_n), allocatable :: list_node

    ! add node to start of link list
    allocate(list_node)
    list_node%val = val
    list_node%next_node => list%first_node
    list%first_node = list_node

  end subroutine unshift

  function shift(list) result(val)
    type(list_t), intent(inout) :: list
    integer :: val
    type(list_n) , pointer:: tnode_ptr

    ! Remove node from start of list
    ! check if there is a node to remove
    if (.not. associated(list%first_node)) return
    
    tnode_ptr => list%first_node
    val = tnode_ptr%val
    list%first_node => tnode_ptr%next_node
    deallocate(tnode_ptr) 
    
  end function shift

  function length(list) result(n)
    type(list_t), intent(in) :: list
    integer :: n
    type(list_n) , pointer:: tnode_ptr
    
    n = 0

    ! tranverse the list to find the last node
    tnode_ptr => list%first_node
    do while (associated(tnode_ptr%next_node))
       n = n + 1
       tnode_ptr => tnode_ptr%next_node
    end do
  end function length

  subroutine delete(list, val)
    type(list_t), intent(inout) :: list
    integer :: val
    type(list_n) , pointer:: tnode_ptr1, tnode_ptr2
    ! If there arent any nodes then just return
    if (.not. associated(list%first_node)) return
    ! if the first node is the one to delete
    if (list%first_node%val == val) then
        deallocate(list%first_node)
        nullify(list%first_node)
        return
    endif    
    ! find the node with the value and delete it
    tnode_ptr1 => list%first_node
    tnode_ptr2 => tnode_ptr1%next_node
    do while (associated(tnode_ptr2%next_node))
       if (tnode_ptr2%val == val) then
           tnode_ptr1%next_node = tnode_ptr2%next_node    
           deallocate(tnode_ptr2)
           exit
       end if    
       tnode_ptr1 => tnode_ptr2
       tnode_ptr2 => tnode_ptr2%next_node
    end do

  end subroutine delete

  subroutine destroy(list)
    type(list_t), intent(inout) :: list
    type(list_n) , pointer:: tnode_ptr1, tnode_ptr2
    
    tnode_ptr1 => list%first_node
    do while (associated(tnode_ptr1%next_node))
           tnode_ptr2 => tnode_ptr1%next_node    
           deallocate(tnode_ptr1)
           tnode_ptr1 => tnode_ptr2
    end do
    !deallocate(list)

  end subroutine destroy

end module
