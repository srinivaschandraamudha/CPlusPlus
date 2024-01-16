#ifndef LIST_H
#define LIST_H

#include "node.h"

enum class list_op{
    undefined = -1,
    exit_op = 0,
    insert_node = 1,
    delete_node = 2,
    find_node = 3,
    display = 4,
    reverse = 5
};

void insert_node(node *node_obj);
node* delete_node(int position);
node* find_node(int data);
node* reverse(node *top_node);
void display();
void list_ops(list_op op);
node* create(int data);
bool isempty();
int listsize();
extern node* top_node;

#endif