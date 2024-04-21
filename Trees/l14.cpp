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
// maxm depth of a binary tree.
int depth(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + max(depth(root->left), depth(root->right));
}
int main()
{

    return 0;
}