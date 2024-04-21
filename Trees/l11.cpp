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
// Iterative postorder using 2 stacks
vector<int> postorder(Node *root)
{
    vector<int> ans;
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        auto front = st1.top();
        st1.pop();
        if (front->left)
            st1.push(front->left);
        if (front->right)
            st1.push(front->right);
        st2.push(front);
    }

    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    return ans;
}

// TC => O(N)
// SC => O(N)+O(N) for 2 stacks
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = postorder(root);
    for (auto i : ans)
    {
        cout << i << " ";
    } // 4 5 2 6 7 3 1
    return 0;
}
