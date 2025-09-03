void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int removeElement(int* nums, int n, int val) {
    int c = 0, i = 0, j = n - 1, f;
    if(n == 0)
        return 0;
    while(i <= j)
    {
        f = 1;
        if(nums[i] == val)
        {
            if(nums[j] != val)
            {
                // swap val with a other element
                swap(&nums[i], &nums[j]);
                c++;
                j--;
                f = 1;
            }
            else
            {
                j--;
                f = 0;
            }
                
        } 
        if(f)
            i++; 
    }
    return j + 1;
}
