class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>ans(26,false);
        for(char ch:sentence){
            ans[ch-'a'] = true;
        }
        for(int i = 0;i<26;i++){
            if(!ans[i]) return false;
        }
        return true;
    }
};