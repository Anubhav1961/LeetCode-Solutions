class Solution {
public:
    vector<string>ans;
    void solve(string s,int o,int c,int n){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(o<n){
            solve(s+'(',o+1,c,n);
        }
         if(c<o){
            solve(s+')',o,c+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("",0,0,n);
        return ans;
    }
};