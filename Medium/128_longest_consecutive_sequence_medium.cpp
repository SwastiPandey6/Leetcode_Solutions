// 128. Longest Consecutive Sequence
// Difficulty: Medium
// Approach: Hash Set
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> st;

        for (int num : nums) {
            st.insert(num);
        }

        int longest = 1;

        for (int it : st) {
            // Start only if it's the beginning of a sequence
            if (st.find(it - 1) == st.end()) {
                int x = it;
                int cnt = 1;

                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};