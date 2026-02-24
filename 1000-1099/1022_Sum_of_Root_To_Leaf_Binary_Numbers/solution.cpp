#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current_val) {
        if (node == nullptr) {
            return 0;
        }

        // Shift current value left by 1 and add the node's value
        // Using bitwise operations: (current_val << 1) | node->val
        current_val = (current_val * 2) + node->val;

        // If it's a leaf node, return the final calculated value for this path
        if (node->left == nullptr && node->right == nullptr) {
            return current_val;
        }

        // Otherwise, return the sum of the left and right subtree paths
        return dfs(node->left, current_val) + dfs(node->right, current_val);
    }
};

// Helper function to build a tree from level-order input (used for local testing)
// Use -1 in your input.txt to represent 'null' nodes.
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        // Left Child
        if (nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        
        // Right Child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    // File I/O setup
    freopen("D:/Github/leetcode/input.txt", "r", stdin);

    vector<int> nodes;
    int val;
    
    // Read all integers from input.txt into a vector
    // Input format example: 1 0 1 0 1 0 1
    while (cin >> val) {
        nodes.push_back(val);
    }

    if (!nodes.empty()) {
        TreeNode* root = buildTree(nodes);
        Solution sol;
        cout << "Sum: " << sol.sumRootToLeaf(root) << endl;
    } else {
        cout << "Input file is empty or invalid." << endl;
    }

    return 0;
}