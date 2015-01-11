#include <iostream>
#include <memory>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}

      ~TreeNode() {
          //cout << "~" << val << "~";
          delete left;
          delete right;
      }
 };

TreeNode* buildExampleTree(int off = 0)
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    if (off)
    root->right->right = new TreeNode(7);

    return root;
}

void printTree(TreeNode* root)
{
    if (root->left) printTree(root->left);
    cout << "[" << root->val << "]";
    if (root->right) printTree(root->right);
}

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p==nullptr && q==nullptr)
            return true;
        if (p==nullptr || q ==nullptr)
            return false;
        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right);
    }
};

int main()
{
    Solution s;
    unique_ptr<TreeNode> root1(buildExampleTree());
    unique_ptr<TreeNode> root2(buildExampleTree(1));

    std::cout << s.isSameTree(root1.get(), root2.get()) << "\n";
}
