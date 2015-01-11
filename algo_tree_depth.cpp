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
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return traverse(root, 1);
    }
private:
    int traverse(TreeNode *root, int level)
    {
        int res = level;
        int resLeft = 0, resRight = 0;
        if (root->left) resLeft = traverse(root->left, level + 1);
        if (root->right) resRight = traverse(root->right, level + 1);

        return resLeft > resRight ? (resLeft > res ? resLeft : res) : (resRight > res ? resRight : res);
    }
};

int main()
{
    Solution s;
    unique_ptr<TreeNode> root(buildExampleTree());

    std::cout << s.maxDepth(root.get()) << "\n";
    std::cout << s.maxDepth(nullptr) << "\n";
    std::cout << s.maxDepth(new TreeNode(0)) << "\n";
}
