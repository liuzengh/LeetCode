class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int hasZero = false;
        vector<int> dp_pos(nums.size() + 1, 0);
        vector<int> dp_neg(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                dp_pos[i+1] = dp_neg[i+1] = 0;
                hasZero = true; 
            }
            else if(nums[i] < 0)
            {
                dp_pos[i+1] = dp_neg[i] * nums[i];
                dp_neg[i+1] = min(dp_pos[i] * nums[i], nums[i]);
            }
            else
            {
                dp_pos[i+1] = max(dp_pos[i] * nums[i], nums[i]);
                dp_neg[i+1] = dp_neg[i] * nums[i];
            }
        }
        int res = *max_element(dp_pos.begin(), dp_pos.end());
        if(res == 0)
        {
            if(hasZero) res = 0;
            else 
            {
                res = INT_MIN;
                for(auto &&x: dp_neg)
                {
                    if(x != 0  && x > res)
                        res = x;
                }
            }
        }
            
        return res;
    }
};