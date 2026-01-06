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
