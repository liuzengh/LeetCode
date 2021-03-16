
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 不考虑重复。
    // 1. 升序排序后取前k个数 O(k + NlogN)
    // 2. 建立二叉堆，然后依次从堆中取走k个数 O(N + klogN)
    // 3. 借助快速排序的思想，进行划分，时间复杂度为\Theta(N)
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        make_heap(arr.begin(), arr.end(), greater<int>());
        for(int i = 0; i < k; ++i)
            pop_heap(arr.begin(), arr.end()-i, greater<int>());
        return vector<int>(arr.end()-k, arr.end());
    }
};