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
