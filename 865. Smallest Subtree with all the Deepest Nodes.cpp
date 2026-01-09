/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth = 0;
    int solve(TreeNode* root, int d, TreeNode* &ans) {
        if(root == NULL) {
            maxDepth = max(maxDepth, d);
            return d;
        }

        int left = solve(root -> left, d+1, ans);
        int right = solve(root -> right, d+1, ans);
        if(left == maxDepth && right == maxDepth) ans = root;
        return max(left, right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans;
        solve(root, 0, ans);
        return ans;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lcaDeepestLeaves(root);
    }
};
