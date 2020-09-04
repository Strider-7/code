#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> total(int start, int end)
{
    vector<TreeNode *> res;
    if (start > end)
    {
        res.push_back(nullptr);
        return res;
    }
    if (start == end)
    {
        res.push_back(new TreeNode(start));
        return res;
    }
    vector<TreeNode *> left, right;
    for (int i = start; i <= end; i++)
    {
        left = total(start, i - 1);
        right = total(i + 1, end);
        for (auto p : left)
        {
            for (auto q : right)
            {
                TreeNode *root = new TreeNode(i);
                root->left = p;
                root->right = q;
                res.push_back(root);
            }
        }
    }
    return res;
}
vector<TreeNode *> generateTrees(int n)
{
    vector<TreeNode *> res;
    if (n == 0)
        return res;
    return total(1, n);
}