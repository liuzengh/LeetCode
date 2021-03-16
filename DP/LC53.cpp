
1. 定义子问题：定义dp[i]为以nums[i]结尾的最大数组和
2. 定义原问题和子问题的关系：
dp[i]中肯定包含nums[i]，但是包不包括nums[i]之前的一段连续的区间数呢？如果dp[i-1]大于0，则dp[i] = num[i]+dp[i-1]，此时的dp[i]肯定比只包含nums[i]更大。
3. 边界条件：要考虑 i - 1 必须大于等于0， i 小于等于 n - 1, n为数组的长度。
4. 初始化：dp[0] = nums[0]
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        for(int i = 1; i < nums.size(); ++i)
            dp[i] = nums[i] + max(0, dp[i-1]);
        return *max_element(dp.begin(), dp.end());
    }
};