#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // If the helper function returns -1, it means the tree is unbalanced.
        return checkHeight(root) != -1;
    }

private:
    // Helper function that returns the height of the tree if balanced, 
    // or -1 if unbalanced.
    int checkHeight(TreeNode* node) {
        if (node == nullptr) return 0;

        // Recursively check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Propagate failure up immediately

        // Recursively check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Propagate failure up immediately

        // Check the balance condition at the current node
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Current node is unbalanced
        }

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }
};

// Helper function to build a simple tree for testing
TreeNode* buildTree() {
    // Example: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTree();
    
    if (sol.isBalanced(root)) {
        cout << "Tree is balanced." << endl;
    } else {
        cout << "Tree is NOT balanced." << endl;
    }

    // Clean up memory (omitted for brevity in competitive programming context)
    return 0;
}