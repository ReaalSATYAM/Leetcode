class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;

        for (int i = 0; i < spells.size(); i++)
        {
            int lo = 0;
            int hi = potions.size();

            while (lo < hi)
            {
                int mid = lo + (hi - lo) / 2;
                long long product = 1ULL * spells[i] * potions[mid];

                if (product < success)
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid;
                }
            }

            result.push_back(potions.size() - lo);
        }

        return result;
    }
};
