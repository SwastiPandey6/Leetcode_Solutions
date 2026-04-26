// 560. Subarray Sum Equals K
// Difficulty: Medium
// Approach: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int sum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (mpp.find(sum - k) != mpp.end()) {
                count += mpp[sum - k];
            }

            mpp[sum]++;
        }

        return count;
    }
};