class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp(envelopes.size(), 1);
        auto cmp =  [](const vector<int> &lhd, const vector<int> &rhd){
              return  lhd[0] < rhd[0] || (lhd[0] == rhd[0] && lhd[1]<rhd[1]);
            };
        sort(envelopes.begin(), envelopes.end(), cmp);
        for(int i = 1; i < envelopes.size(); ++i)
            for(int k = i - 1; k >= 0; --k)
            {
                if(envelopes[k][0] < envelopes[i][0] 
                    && envelopes[k][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[k]+1);
            }
        return *max_element(dp.begin(), dp.end());
    }
};