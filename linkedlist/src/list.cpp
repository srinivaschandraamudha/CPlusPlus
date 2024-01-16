#include "list.h"
using namespace std;
node* top_node = NULL;

#define ISEMPTY (top_node == NULL) ? true : false

node* create(int data)
{
    return (new node(data));
}

int listsize()
{
    int size = 0;
    for(node* obj = top_node; obj != NULL; obj = obj->next_node) 
    { 
        size++;
    }
    return size;
}

void insert_node(node *node_obj)
{
    cout << "In insert node." << endl;
    if(!top_node)
        top_node = node_obj;
    else 
    {
        node* obj = top_node;
        for(; obj->next_node != NULL; obj = obj->next_node) {}
        obj->next_node = node_obj;
    }
}

node* delete_node(int position)
{
    cout << "In delete node. " << position << endl;
    node* popped_node = NULL;
    if(ISEMPTY)
        cout << "List empty." << endl; 
    else
    {
        if((position <= listsize()) && (0 < position))
        {
            node* obj = top_node;
            node* prev_node = NULL;
            if(1 == position)
            {
                top_node = top_node->next_node;
                popped_node = obj;
                popped_node->next_node = NULL;
            }
            else
            {
                for(int index = 1 ; index < position ; index++)
                {
                    prev_node = obj;
                    obj = obj->next_node;

                }
                popped_node = obj;
                prev_node->next_node = popped_node->next_node;
                popped_node->next_node = NULL;
            }
        }
    }           
    return popped_node;
}

node* find_node(int data)
{
    node* target_node = NULL;
    if(ISEMPTY)
        cout << "List is empty." << endl;
    else
    {
        node* obj ;
        for(obj = top_node; obj != NULL; obj = obj->next_node)
        {
            if (data == obj->get_data())
            {
                target_node = obj;
                break;
            }
        }
    }        
    return target_node;
}

void display()
{
    if(ISEMPTY)
        cout << "List is empty." << endl;
    else
    {
        node* obj ;
        for(obj = top_node; obj != NULL; obj = obj->next_node)
        {
            cout << "Node " <<  obj << ": data is " << obj->get_data() << endl;
        }
    }        
}

node* reverse(node *top_node)
{
    node *previous = NULL;
    node *currentnode = top_node;
    node *nextnode = NULL;
    if(ISEMPTY)
        cout << "List is empty." << endl;
    else
    {
        while (currentnode != NULL)
        {
            nextnode = currentnode->next_node;
            currentnode->next_node = previous;
            previous = currentnode;
            currentnode = nextnode;
        }
    }
    return previous;
}

void list_ops(list_op op)
{
    switch(op)
    {
        case list_op::insert_node:
            {
                int input;
                cout << "Enter integer data to be pushed." << endl;
                cin >> input;
                insert_node((create(input)));
                break;
            }
        case list_op::delete_node:
            {
                int position;
                cout << "Enter position of node in integer." << endl;
                cin >> position;
                node* deleted_node = delete_node(position);
                if(deleted_node)
                    cout << "Deleted Node from the list " << deleted_node  << ": data is " << deleted_node->get_data() << endl;
                else
                    cout << "Position entered is greater than length of the list." << endl;
                break;
            }
        case list_op::find_node:
            {
                int target;
                cout << "Enter integer data to be found in list." << endl;
                cin >> target;
                node* target_node = find_node(target);
                if(target_node)
                    cout << "Found target node from the list" << target_node  << ": data is " << target_node->get_data() << endl;
                else
                    cout << "Target not found in list." << endl;
                break;
            }
        case list_op::display:
            {
                cout << "Displaying list." << endl;
                display();
                break;
            }
        case list_op::reverse:
            {
                cout << "Reversing list." << endl;
                top_node = reverse(top_node);
                cout << "main logic debug: " << endl;
                display();
                cout << "main logic debug end." << endl;
                break;
            }
        default:
            {
                cout<< "No operation." << endl;
                break;
            }
    };
}