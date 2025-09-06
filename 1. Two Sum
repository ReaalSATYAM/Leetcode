int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                *returnSize = 2;
                int *idx = (int *)malloc(2 * sizeof(int));
                idx[0] = i;
                idx[1] = j;
                return idx;                
            }
        }
    }
    return 0;
}
