#ifndef AVLTREE_H
#define AVLTREE_H

class AvlTree
{
    public:
        AvlTree();
        ~AvlTree();
        AvlTree (const AvlTree &original);
        AvlTree &operator=(const AvlTree &rhs);

        void outputTree();
        void addKey(int);
        void deleteKey(int);
        bool findKey(int);

    private:
        struct Node
        {
            int key;
            Node *right;
            Node *left;
            int height;

            Node(int datum)
            {
                right=nullptr;
                left=nullptr;
                key=datum;
                height=1;
            };
        } *root;

        void copyOfTree(Node*&, Node*);
        void deleteTree(Node*);
        void outputTree(Node*, int);

        Node* addKey(Node*, int);
        Node* findMin(Node*);
        Node* deleteMin(Node*);
        Node* deleteKey(Node*, int);
        Node* findKey(Node*, int);

        int height(Node*);
        int balanceFactor(Node*);
        void fixHeight(Node*);
        Node* rotateRight(Node*);
        Node* rotateLeft(Node*);
        Node* balancing(Node*);

};

#endif // AVLTREE_H
