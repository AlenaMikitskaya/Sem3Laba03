#include <iostream>
#include "avlTree.h"

using namespace std;

int main()
{
    cout<<"To add key enter 1"<<endl;
    cout<<"To output tree enter 2"<<endl;
    cout<<"To delete key enter 3"<<endl;
    cout<<"To copy tree enter 4"<<endl;
    cout<<"For exit enter 0"<<endl;

    int operation;
    AvlTree tree;

    while (true)
    {
        cout<<endl<<"Enter the operation: ";
        cin>>operation;

        if(operation==1)
        {
            int key;
            cout<<"Enter key = ";
            cin>>key;
            tree.addKey(key);
        }
        if(operation==2)
        {
            tree.outputTree();
        }
        if(operation==3)
        {
            int key;
            cout<<"Enter key = ";
            cin>>key;
            if(tree.findKey(key))
            {
                tree.deleteKey(key);
                tree.outputTree();
            }
        }
        if(operation==4)
        {
            AvlTree tree1;
            tree1=tree;
            tree1.outputTree();
        }
        if(operation==0)
        {
            break;
        }
    }
    return 0;
}

