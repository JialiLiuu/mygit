#include "common.h"

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void createTree(TreeNode *pRoot, int *num)
{
    TreeNode *p = pRoot;
    vector<TreeNode *> nodes;
    nodes.push_back(p);
    nodes.push_back(p);
    for (int i = 0; i < 12; i++)
    {
        if (i % 2 == 0)
        {
            if (*(num + i) != -1)
            {
                TreeNode *t = new TreeNode;
                t->val = *(num + i);
                nodes[i]->left = t;
                nodes.push_back(t);
                nodes.push_back(t);
            }
            else
                nodes[i]->left = nullptr;
        }
        else
        {
            if (*(num + i) != -1)
            {
                TreeNode *t = new TreeNode;
                t->val = *(num + i);
                nodes[i]->right = t;
                nodes.push_back(t);
                nodes.push_back(t);
            }
            else
                nodes[i]->right = nullptr;
        }
    }
}

class Solution
{
public:
    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return 0;
        if (pRoot->left == nullptr && pRoot->right == nullptr)
            return 1;
        else if (pRoot->left != nullptr && pRoot->right == nullptr)
        {
            return TreeDepth(pRoot->left) + 1;
        }
        else if (pRoot->left == nullptr && pRoot->right != nullptr)
        {
            return TreeDepth(pRoot->right) + 1;
        }
        else
        {
            int n1 = TreeDepth(pRoot->left) + 1;
            int n2 = TreeDepth(pRoot->right) + 1;
            return n1 > n2 ? n1 : n2;
        }
    }
};

int main()
{
    Solution S;
    TreeNode *pRoot = new TreeNode;
    pRoot->val = 1;
    int num[] = {2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1};
    createTree(pRoot, num);
    if (pRoot->left->left->left == NULL)
        cout << 1 << endl;
    else
        cout << pRoot->left->left->left->left->left->val << endl;
    // cout << S.TreeDepth(pRoot) << endl;
}