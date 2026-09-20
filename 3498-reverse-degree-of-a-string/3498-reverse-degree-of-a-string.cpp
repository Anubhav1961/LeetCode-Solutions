class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, pair<int, int>> mp;

        int idx = 1;
        int alphaIdx = 26;

        for(char ch = 'a'; ch <= 'z'; ch++) {
            mp[ch] = {alphaIdx, idx};
            alphaIdx--;
            idx++;
        }

        int sum = 0;

        int pos = 1;
        for(char ch : s) {
            int reverseIdx = mp[ch].first;
            sum += reverseIdx * pos;
            pos++;
        }

        return sum;
    }
};