class Solution {
public:
    string greatestLetter(string s) {
        string ans = "";
        for(char ch = 'Z';ch>='A';ch--){
            bool upper = false;
            bool lower = false;
            for(char x:s){
                if(x==ch){
                    upper = true;
                }
                else if(x==ch+32){
                    lower = true;
                }
            }
            if(upper && lower)
            {
                ans+=ch;
                return ans;
            }
        }
        return "";
    }
};