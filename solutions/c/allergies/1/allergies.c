#include "allergies.h"
#include <stdio.h>
bool is_allergic_to(allergen_t a, int tr){
    if (tr & (1<<a)) return true;
    return false;
}
allergen_list_t get_allergens (allergen_t tr) {
    allergen_list_t list;
    
    int ai=0;
    for (int i=0; i<ALLERGEN_COUNT; i++) {
        
        if ((tr & (1<<i))>0) {
            list.allergens[i]=true;
            ai++;
        }
    }
    list.count=ai;
    return list;    
}