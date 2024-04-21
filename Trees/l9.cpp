#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// iterative preorder.
void preorder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        auto top = st.top();
        st.pop();
        cout << top->data << " ";
        if (top->right)
        {
            st.push(top->right);
        }
        if (top->left)
        {
            st.push(top->left);
        }
    }
}

// TC => O(n)
// SC => O(n)

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root); // 1 2 4 5 3 6 7
    return 0;
}