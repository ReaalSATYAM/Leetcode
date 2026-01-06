/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
*/
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        int level = 1;
        int minLevel;
        int maxSum = INT_MIN;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            int currSum = 0;
            for(int i = 0; i < levelSize; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();

                currSum += currNode-> val;
                if(currNode->left != nullptr){
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr){
                    q.push(currNode->right);
                }
            } 

            if(currSum > maxSum){
                maxSum = currSum;
                minLevel = level;
            } 
            level++;
        }
        return minLevel;
    }
};
