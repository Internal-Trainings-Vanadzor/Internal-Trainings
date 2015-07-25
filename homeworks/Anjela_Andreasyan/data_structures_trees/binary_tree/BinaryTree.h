struct Node
{
    int value;
    Node *left;
    Node *right;
};

class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int value);
        Node *search(int value);
        void destroy();
        bool exists(int value);
        bool isEmpty();

    private:
        void destroy(Node *leaf);
        void insert(int value, Node *leaf);
        Node *search(int value, Node *leaf);

        Node *root;
};
