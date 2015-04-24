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
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->left->left = new TreeNode(3);

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
    bool isValidBST(TreeNode *root) {
        if (!root) return true;

        if (root->left) {
            if (root->val <= root->left->val) {
                return false;
            }
        }
        if (root->right) {
            if (root->val >= root->right->val) {
                return false;
            }
        }

        bool resLeft = isValidBST(root->left);
        bool resRight = isValidBST(root->right);

        return resLeft && resRight;
    }
};

int main()
{
    Solution s;
    unique_ptr<TreeNode> root(buildExampleTree());

    std::cout << s.isValidBST(root.get()) << "\n";
}
