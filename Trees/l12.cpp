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
// Iterative postorder using 1 stack
vector<int> postorder(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        auto front = st.top();
        st.pop();
        if (front->left)
            st.push(front->left);
        if (front->right)
            st.push(front->right);
        ans.push_back(front->data);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> striverPostOrder(Node *root)
{
    stack<Node *> st;
    vector<int> ans;
    auto curr = root;
    while (curr || !st.empty())
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            auto temp = st.top()->right;
            if (!temp)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return ans;
}

// TC => O(N)
// SC => O(N) for 1 stack
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
