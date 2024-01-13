#ifndef NODE_H
#define NODE_H
#include <iostream>

class node {
    private:
        int data;
    public:
        node *next_node;
        int get_data() { return data; };
        void set_data(int change_data) { data = change_data; };
        node(int input_data): data(input_data), next_node(NULL) {};
};

#endif