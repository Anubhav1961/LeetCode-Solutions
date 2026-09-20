class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, int> mp;

        int alphaIdx = 26;

        for(char ch = 'a'; ch <= 'z'; ch++) {
            mp[ch] = alphaIdx;
            alphaIdx--;
        }

        int sum = 0;
        int pos = 1;

        for(char ch : s) {
            sum += mp[ch] * pos;
            pos++;
        }

        return sum;
    }
};