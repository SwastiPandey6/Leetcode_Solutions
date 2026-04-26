// 1. Two Sum
// Difficulty: Easy
// Approach: Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            int moreNeeded = target - nums[i];

            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }

            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }
};