#include <iostream>
#include <vector>

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

void printVector(const vector<vector<int> >& vec)
{
    for (const auto& v: vec) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

class Solution {
public:
    using vvi_t = vector<vector<int> >;

    vector<vector<int> > levelOrderBottom(TreeNode *root) {

        vvi_t result;

        if (root) {
            traverseInOrder(root, 1, result);
        }

        return std::move(result);
    }

    vector<vector<int> > levelOrder(TreeNode *root) {

        vvi_t result;

        if (root) {
            traverseInOrder(root, 1, result);
        }

        return std::move(result);
    }

private:
    void traverse(TreeNode *root, int level, vvi_t& result)
    {
        if (result.size() < level) {
            result.insert(result.begin(), vector<int>());
        }
        result[result.size()-level].push_back(root->val);

        if (root->left) traverse(root->left, level + 1, result);
        if (root->right) traverse(root->right, level + 1, result);
    }

    void traverseInOrder(TreeNode *root, int level, vvi_t& result)
    {
        if (result.size() < level) {
            result.push_back(vector<int>());
        }
        result[level-1].push_back(root->val);

        if (root->left) traverseInOrder(root->left, level + 1, result);
        if (root->right) traverseInOrder(root->right, level + 1, result);
    }
};

int main()
{
    Solution s;
    TreeNode* tree = buildExampleTree();

//    vector<vector<int>> res = s.levelOrderBottom(tree);
    vector<vector<int>> res = s.levelOrder(tree);

    printVector(res);
}
