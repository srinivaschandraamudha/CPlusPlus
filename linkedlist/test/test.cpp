#include "list.h"

using namespace std;

void test_insert(int input)
{
    cout << "Testing insert node." << endl;
    insert_node((create(input)));
    node* target_node = find_node(input);
    if(input == target_node->get_data())
        cout << "PASSED:Testing insert node." << endl;
    else
        cout << "FAILED:Testing insert node." << endl;

}

void test_delete(int position, int input)
{
    cout << "Testing delete node." << endl;
    node* deleted_node = delete_node(position);
    if(input == deleted_node->get_data())
        cout << "PASSED:Testing delete node." << endl;
    else
        cout << "FAILED:Testing delete node." << endl;
}

void test_display()
{
    cout << "Testing display list." << endl;
    display();
    // TODO: Add verification hooks
    // 1) Either have return value implemented for returning sucess and failure.
    // 2) Use utilities to verify success or failure via console messages.
}

void test_find(int input)
{
    cout << "Testing search list." << endl;
    node* target_node = find_node(input);
    if(input == target_node->get_data())
        cout << "PASSED:Testing search list." << endl;
    else
        cout << "FAILED:Testing search list." << endl;
}

int main()
{
    cout << "Test started" << endl;
    int input_data = 5;
    int position = 1;
    test_insert(input_data);
    test_display();
    test_find(input_data);
    test_delete(position, input_data);
    cout << "Test end" << endl;
}