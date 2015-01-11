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

TreeNode* buildExampleTree()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = new TreeNode(5);
;

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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        return traverse(root, 1);
    }
private:
    int min(int a, int b) {
        return a < b ? a : b;
    }

    int traverse(TreeNode *root, int level)
    {
        int resLeft = -1, resRight = -1;
        if ((!root->left) && (!root->right))
            return level;

        if (root->left) resLeft = traverse(root->left, level + 1);
        if (root->right) resRight = traverse(root->right, level + 1);

        if (root->left && root->right) min(resRight, resLeft);
        else if (root->left) return resLeft;
        else return resRight;
    }
};

int main()
{
    Solution s;
    unique_ptr<TreeNode> root(buildExampleTree());

    std::cout << s.minDepth(root.get()) << "\n";
    std::cout << s.minDepth(nullptr) << "\n";
    std::cout << s.minDepth(new TreeNode(0)) << "\n";
}
