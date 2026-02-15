#include "sublist.h"
#include <stdio.h>

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count){
    if (base_list_element_count == 0 && base_list_element_count == list_to_compare_element_count) return EQUAL;                               
    if (base_list_element_count >= list_to_compare_element_count) {
        for (size_t bi=0;bi<base_list_element_count;bi++) {
            size_t ai;
            for (ai=0;ai<list_to_compare_element_count;ai++){
                if (list_to_compare[ai]!=base_list[bi+ai]) break;
            } 
            if (ai==list_to_compare_element_count && 
                list_to_compare_element_count==base_list_element_count) return EQUAL;
            if (ai==list_to_compare_element_count) return  SUBLIST;    
        } 
    } else {
        for (size_t ai=0;ai<list_to_compare_element_count;ai++) {
            size_t bi;
            for (bi=0;bi<base_list_element_count;bi++){
                if (list_to_compare[bi+ai]!=base_list[bi]) break;
            } 
            if (bi==base_list_element_count) return SUPERLIST;                                
        }
    }  
    return UNEQUAL;           
}

