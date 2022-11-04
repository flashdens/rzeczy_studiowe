#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node () {
        val = 0;
        left = right = 0;
    }

    Node (int _val) {
        val = _val;
        left = right = 0;
    }
};

class BinarySearchTree {
public:
    Node *root;

    BinarySearchTree() {

    }

    BinarySearchTree (int val) {
        root = new Node(val);
    }

    Node *insert (BinarySearchTree& BST, Node *workingNode, int _val) {
        if (!workingNode){
            Node *insertMe = new Node(_val);
            if (!BST.root)
                return BST.root = insertMe;
            else return insertMe;
        }
        if (workingNode->val < _val) {
            workingNode->right = insert(BST, workingNode->right, _val);
        }

        else if (workingNode->val > _val) {
            workingNode->left = insert(BST,workingNode->left, _val);
        }
        return workingNode;
    }

    void preorder (BinarySearchTree& BST, Node *workingNode){
        if (!workingNode)
            return;
        cout << workingNode->val << " ";
        preorder(BST, workingNode->left);
        preorder(BST, workingNode -> right);
    }

    void inorder (BinarySearchTree& BST, Node *workingNode){
        if (!workingNode)
            return;
        inorder(BST, workingNode->left);
        cout << workingNode->val << " ";
        inorder(BST, workingNode -> right);
    }

    void postorder (BinarySearchTree& BST, Node *workingNode){
        if (!workingNode)
            return;
        postorder(BST, workingNode->left);
        postorder(BST, workingNode -> right);
        cout << workingNode->val << " ";
    }


};

void insertTab (int* tab, int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        cin >> tab[i];
    }
}

void insertTree (BinarySearchTree& dzefko, int tab[], int rozmiar){
    for (int i = 0; i < rozmiar; ++i) {
        dzefko.insert(dzefko, dzefko.root, tab[i]);
    }
}


int main () {
    int rozmiar;
    cin >> rozmiar;
    int valTab[rozmiar-1];
    insertTab(valTab, rozmiar);
    BinarySearchTree dzefko = *new BinarySearchTree ();
    insertTree(dzefko, valTab, rozmiar);
    cout << "PREORDER: ";
    dzefko.preorder(dzefko, dzefko.root);
    cout << endl;
    cout << "INORDER: ";
    dzefko.inorder(dzefko, dzefko.root);
    cout << endl;
    cout << "POSTORDER: ";
    dzefko.postorder(dzefko, dzefko.root);
    cout << endl;
    return 0;
}
