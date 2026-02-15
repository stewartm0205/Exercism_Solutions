#include "list_ops.h"
#include <stdio.h>
#include <stdlib.h>

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]){
 
    list_t* nl = (list_t*)malloc(length * sizeof(list_element_t)+8);
    nl->length = length;
    for (size_t i=0; i<length; i++) {
        nl->elements[i]=elements[i];
    }

    return nl;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2){
    list_t* rl = (list_t*)malloc(list1->length+list2->length+32*sizeof(list_element_t)+8);
    size_t rli=0;
    for (size_t li=0; li < list1->length; li++){
        rl->elements[rli++]=list1->elements[li];
    }

    for (size_t li=0; li < list2->length; li++){
        rl->elements[rli++]=list2->elements[li];
 
    }
    rl->length=rli;
    return rl;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
   
    list_t* rl = (list_t*)malloc(list->length * sizeof(list_element_t));
    size_t rli=0;
    for (size_t li=0; li <= list->length; li++) {
        if (filter(list->elements[li])) {
            rl->elements[rli++]=list->elements[li];
        }
    }
    rl->length=rli;
    return rl;
}

// returns the length of the list
size_t length_list(list_t *list){
    return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
    list_t* rl = (list_t*)malloc(list->length * sizeof(list_element_t));
    size_t li;
    for (li=0; li < list->length; li++) {
        rl->elements[li]=map(list->elements[li]);
    }
    rl->length=li;
    return rl;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)){
    list_element_t r = initial;
    if (list == NULL) return r;
    for (size_t li=0; li < list->length; li++) {
       r=foldl(list->elements[li],r);
    }
    return r;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)){
    list_element_t r = initial;
    if (list->length == 0) return r;
    size_t li;
    for (li=list->length-1; li > 0; li--) {
        r=foldr(list->elements[li], r);
    }
    r=foldr(list->elements[li], r);
    return r;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list){
    list_t* rl = (list_t*)malloc(list->length * sizeof(list_element_t));
    size_t rli = list->length - 1;
    for (size_t li=0; li < list->length; li++) {
        rl->elements[rli--]=list->elements[li];
    }
    rl->length=list->length;
    return rl;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list){
    free(list);
    return;
}