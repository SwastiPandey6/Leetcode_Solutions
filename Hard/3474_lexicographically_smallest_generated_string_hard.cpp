// 3474. Lexicographically Smallest Generated String
// Difficulty: Hard

class Solution {
public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?');

        // Process 'T'
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') continue;

            for (int j = 0; j < m; j++) {
                if (ans[i + j] != '?' && ans[i + j] != t[j]) {
                    return "";
                }
                ans[i + j] = t[j];
            }
        }

        string old_ans = ans;

        // Fill remaining with 'a'
        for (char &c : ans) {
            if (c == '?') c = 'a';
        }

        // Process 'F'
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') continue;

            if (string(ans.begin() + i, ans.begin() + i + m) != t) continue;

            bool ok = false;
            for (int j = i + m - 1; j >= i; j--) {
                if (old_ans[j] == '?') {
                    ans[j] = 'b';
                    ok = true;
                    break;
                }
            }

            if (!ok) return "";
        }

        return ans;
    }
};