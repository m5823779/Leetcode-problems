class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // method 1: brute force (hash set)
        const int n = s.size();
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            set<char> seen;
            for (int j = i; j < n; j++) {
                seen.insert(s[j]);
                if (j - i + 1 != seen.size()) {
                    break;
                }
                max_len = max(max_len, j - i + 1);
            }
        }
        return max_len;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // method 1: brute force
        // 1. enumerate <i>
        // 2. create 128 dimension [ASCII] vector "seen" to store appeare times for each characters
        // 3. declear pointer j start from i, move j until current char have already appare
        // 5. ans = max(ans, j - 1)
        
        const int n = s.size();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            vector<int> seen(128, 0);

            for (int j = i; j < n; j++) {
                if (seen[s[j]]) {
                    break;
                }
                seen[s[j]]++;
                max_len = max(max_len, j - i + 1);
            }
        }
        return max_len;
    }
    // time complexity: O(n * 128)
    // space complexity: O(128)
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // method 2: sliding window
        const int n = s.size();
        int ans = 0;

        set<char> seen;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    // time compleixty: O(n)
    // space complexity: O(128)
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // method 2: sliding window
        // example:
        // 0 1 2 3 4 5 6 7
        // a b c a b c b b
        //  i   j       indies      substring
        //  0   0        {a:0}          a
        //  0   1      {a:0, b:1}       ab
        //  0   2    {a:0, b:1, c:2}    abc
        //  1   3    {a:3, b:1, c:2}    bca
        //  2   4    {a:3, b:4, c:2}    cab
        //  3   5    {a:3, b:4, c:5}    abc
        //  5   6    {a:3, b:6, c:5}    cb
        //  7   7    {a:0, b:7, c:5}    b
        
        // 1. create 128 dimension vector "last_ind" to store last indies of each character, initial as -1
        // 2. enumerate <i, j> which i = max(i, last_ind[s[j]], + 1)
        // 3. ans = max(ans, j - i + 1)
        
        int l = 0;
        int r = 0;
        vector<int> last(128, -1);
        int ans = 0;
        for (r = 0; r < s.size(); r++) {
            l = max(l, last[s[r]] + 1);
            last[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    // time complexity: O(n)
    // sapce complexity: O(128)
};