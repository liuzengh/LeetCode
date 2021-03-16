class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i)
            for(int k = i - 1; k >= 0; --k)
                if(nums[i] > nums[k])
                {
                    if(dp[i] < dp[k] + 1)
                    {
                        dp[i] = dp[k] + 1;
                        count[i] = count[k];
                    }
                    else if(dp[i] == dp[k] + 1)
                        count[i] += count[k];
                }
        int maxVal = *max_element(dp.begin(), dp.end());
        int res = 0;
        for(int i = 0; i < dp.size(); ++i)
            if(dp[i] == maxVal)
                res += count[i];
        return res;
    }
};