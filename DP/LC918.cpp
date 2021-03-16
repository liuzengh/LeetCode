

// 1. 最大值在原数组中 
// 2. 最大值在环形数组中 此时的subArray一定包含A[0]和A[A.length-1], 此时最大值等于 = 原数组和-最小值

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 1) return A[0];
        vector<int> dpp(A);
        vector<int> dpn(A.size(), 0);

        for(int i = 1; i < A.size(); ++i)
            dpp[i] = A[i] + max(0, dpp[i-1]);

        for(int i = 1; i < A.size()-1; ++i)
            dpn[i] = A[i] + min(0, dpn[i-1]);

       return  max(*max_element(dpp.begin(), dpp.end()), 
            accumulate(A.begin(), A.end(), 0) - *min_element(dpn.begin(), dpn.end()));
        
    }
};