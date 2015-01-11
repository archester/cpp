#include <iostream>
#include <memory>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}

      ~TreeNode() {
          cout << "~" << val << "~";
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

class BSTIterator {
public:
    BSTIterator(TreeNode *root): cur_(root) {
    }

    bool hasNext() {
        return false;
    }

    int next() {
    }

private:
    TreeNode* cur_;
};

int main()
{
    unique_ptr<TreeNode> root(buildExampleTree());

    printTree(root.get());


    BSTIterator i = BSTIterator(root.get());
    while (i.hasNext()) cout << i.next();
}
