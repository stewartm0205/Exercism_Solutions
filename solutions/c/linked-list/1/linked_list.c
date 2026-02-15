#include "linked_list.h"

//struct list_node {
//   struct list_node *prev, *next;
//  ll_data_t data;
//};

//struct list {
   //struct list_node *first, *last;
//};

// constructs a new (empty) list
struct list *list_create(void){
   struct list* l=malloc(sizeof(struct list));
   l->first= NULL;
   l->last = NULL;
   return l;
}

// counts the items on a list
size_t list_count(const struct list *list){
   size_t count=0;
   if (list->first == NULL) return 0;
   struct list_node* ln_ptr = list->first;
   while(ln_ptr!=NULL){
      count++;
      ln_ptr=ln_ptr->next;
   }
   return count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data){
   struct list_node* ln_ptr  = malloc(sizeof(struct list_node));
   ln_ptr->data = item_data;
   ln_ptr->prev = list->last;
   ln_ptr->next = NULL;
   if (list->last!=NULL) {
      list->last->next=ln_ptr;
   } 
   list->last = ln_ptr;
   if (list->first == NULL) list->first=ln_ptr;
}

// removes item from back of a list
ll_data_t list_pop(struct list *list){
   if (list->last == NULL) return 0;
   ll_data_t tdata = list->last->data;
   struct list_node* ln_ptr = list->last;
   if (ln_ptr->prev != NULL) {
      ln_ptr->prev->next = NULL;
   }
   list->last = ln_ptr->prev;
   if (list->first == ln_ptr) {
      list->first = NULL;
      list->last = NULL;
   }
   free(ln_ptr);
   return tdata;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data){
   struct list_node* ln_ptr  = malloc(sizeof(struct list_node));
   ln_ptr->next = list->first;
   ln_ptr->prev = NULL;
   ln_ptr->data = item_data;
   list->first = ln_ptr;
   if (list->last == NULL) list->last = ln_ptr;
}

// removes item from front of a list
ll_data_t list_shift(struct list *list){
   if(list->first == NULL) return 0;
   ll_data_t tdata = list->first->data;
   struct list_node* ln_ptr = list->first;
   list->first = ln_ptr->next;
   if(list->first!=NULL)list->first->prev = NULL;
   if(list->first==NULL)list->last = NULL;
   free(ln_ptr);
   return tdata;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data){
//from first to last
   struct list_node* ln_ptr;
   for (ln_ptr = list->first; ln_ptr!=NULL && ln_ptr->data != data; 
      ln_ptr=ln_ptr->next);
   if (ln_ptr !=NULL) {
      if(ln_ptr->prev!=NULL) ln_ptr->prev->next = ln_ptr->next;
      if(ln_ptr->next!=NULL) ln_ptr->next->prev = ln_ptr->prev;
      if(list->first==ln_ptr) list->first = ln_ptr->next;
      if(list->last==ln_ptr) list->last = ln_ptr->prev;
      free(ln_ptr);
   }

}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list){
   struct list_node* ln_ptr;
   for (ln_ptr = list->first; ln_ptr!=NULL; ){
      struct list_node* ptr = ln_ptr;
      ln_ptr=ln_ptr->next;
      free(ptr);
   }
   free(list);
}