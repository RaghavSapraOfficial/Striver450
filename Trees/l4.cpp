// BT traversals in cpp
// 1. Preorder (Root L R) (DFS)
// 2. Postorder (L R Root) (DFS)
// 3. Inorder (L Root R) (DFS)
// 4. Levelorder (BFS)
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

int main()
{
    return 0;
}