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

// level order traveral of Binary Tree.

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            level.push_back(node->data);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
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
    levelOrder(root); // {1} {2,3} {4,5}
    return 0;
}