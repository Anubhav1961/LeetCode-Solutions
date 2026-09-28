class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int cnt = 0;

        stack<char> st;

        for(char ch : s) {
            if(ch == '(') {
                st.push(ch);
                cnt++;
                mx = max(mx, cnt);
            }
            else if(ch == ')') {
                st.pop();
                cnt--;
            }
        }

        return mx;
    }
};