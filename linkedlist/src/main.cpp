#include "list.h"

using namespace std;

int main()
{
    int choice = -1;
    do {
        cout << "Insert node, Enter 1." << endl;
        cout << "Delete node, Enter 2." << endl;
        cout << "Find node, Enter 3." << endl;
        cout << "Display nodes, Enter 4." << endl;
        cout << "Exit, Enter 0." << endl;
        cin >> choice;
        list_ops(static_cast<list_op>(choice));
    }while (0 < choice);
    return 0;
}