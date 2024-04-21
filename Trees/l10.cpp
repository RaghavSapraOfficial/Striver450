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

void inorder(Node *root)
{
    stack<Node *> st;
    Node *node = root;
    while (true)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                return;
            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
}
// Time Complexity: O(n)
// Space Complexity: O(n)

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    inorder(root); // 4 2 5 1 3
    return 0;
}