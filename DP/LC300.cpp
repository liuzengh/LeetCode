1. 定义子问题：定义dp[i]为以nums[i]结尾的最长递增子序列的长度
2. 定义原问题和子问题的关系：
dp[i]肯定至少等于1，但是包不包括nums[i]之前的子序列的长度呢？如果nums[i]大于nums[k](0<=k<i)，则dp[i] = 1+ max{dp[k]}
3. 边界条件：要考虑 0<= k < i, 0 <= i < n, n为数组的长度。
4. 初始化：dp[0] = 1;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i)
            for(int k = i - 1; k>=0; --k)
                if(nums[i] > nums[k])
                    dp[i] = max(dp[i], dp[k] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};