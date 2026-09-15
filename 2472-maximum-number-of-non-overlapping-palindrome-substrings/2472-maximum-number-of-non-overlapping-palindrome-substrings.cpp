class Solution {
public:
    bool isPalindrome(string& s) {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int left = 0;
        int cnt = 0;
        while (left + k <= s.size()) {
            bool found = false;
            string m = s.substr(left, k);
            if (isPalindrome(m)) {
                cnt++;
                left += k;
                found = true;
            } else if (left + k + 1 <= s.size()) {
                string g = s.substr(left, k+1);
                if (isPalindrome(g)) {
                    cnt++;
                    left += k + 1;
                    found = true;
                }
            }
            if(!found) left++;
        }
        return cnt;
    }
};