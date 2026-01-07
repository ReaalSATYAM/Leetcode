/*
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
Note that you need to maximize the answer before taking the mod and not after taking it.
*/
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
private:
    long long totalProduct = 0;
    long long treeSum(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val + treeSum(root->left) + treeSum(root-> right);
    }
    long long product(TreeNode* root, long long totalSum){
        if(!root){
            return 0;
        }
        long long currSum = root->val + product(root->left, totalSum) + product(root-> right, totalSum);

        if(currSum < totalSum){
            totalProduct = max(totalProduct, currSum *(totalSum - currSum));
        }
        return currSum;
    }

public:
    int maxProduct(TreeNode* root) {
        int mod = 1e9 + 7;
        long long totalSum = 0;
        totalSum = treeSum(root);
        product(root, totalSum);
        return int(totalProduct % mod);
    }
};
