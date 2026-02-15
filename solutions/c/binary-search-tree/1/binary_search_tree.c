#include "binary_search_tree.h"

node_t *build_tree(int *tree_data, size_t tree_data_len){
    node_t* top_node = calloc(1,sizeof(node_t));
    for(size_t tdi = 0; tdi < tree_data_len; tdi++){
       add_node(top_node, tree_data[tdi]);
    }
    return top_node; 
}

void add_node(node_t* cur_node, int data) {
    if (cur_node->data == 0) {
        cur_node->data = data;
        return;
    }
    if (data <= cur_node->data) {
        if (cur_node->left==NULL) {
            node_t* new_node=calloc(1,sizeof(node_t));
            new_node->data = data;
            cur_node->left = new_node;
            return;
        } else {
            add_node(cur_node->left, data);
        }
    }
    if (data > cur_node->data) {
        if (cur_node->right==NULL) {
            node_t* new_node=calloc(1,sizeof(node_t));
            new_node->data = data;
            cur_node->right = new_node;
            return;
        } else {
            add_node(cur_node->right, data);
        }
    }
    return;
}

void free_tree(node_t * tree) {
    if (tree->left != NULL) free_tree(tree->left);
    if (tree->right != NULL) free_tree(tree->right);
    free(tree);
}

int *sorted_data(node_t * tree){
    int* sd=calloc(10,sizeof(node_t));
    int *ld=calloc(10,sizeof(node_t));
    int *rd=calloc(10,sizeof(node_t));
    size_t sdi=0;
    if (tree->left!=NULL) ld=sorted_data(tree->left);
    if (tree->right!=NULL) rd=sorted_data(tree->right);
    // merge ld and rd into sd;
    for (size_t ldi=0; ld[ldi]!=0; ldi++) {
        sd[sdi++]=ld[ldi];
    }
    sd[sdi++]=tree->data;
    for (size_t rdi=0; rd[rdi]!=0; rdi++) {
        sd[sdi++]=rd[rdi];
    }
    return sd;
}
