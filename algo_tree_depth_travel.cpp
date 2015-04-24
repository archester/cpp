#include <iostream>
#include <memory>
#include <queue>

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

void traverse(TreeNode* root)
{
    std::queue<TreeNode*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        TreeNode* curNode = nodes.front();
        nodes.pop();
        cout << curNode->val << "\n"; // visit the node
        if (curNode->left) nodes.push(curNode->left);
        if (curNode->right) nodes.push(curNode->right);
    }
}

int main()
{
    unique_ptr<TreeNode> root(buildExampleTree());

    traverse(root.get());
}
