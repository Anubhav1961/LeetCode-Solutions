class Solution {
public:

    set<string> combine(set<string> &a, set<string> &b) {
        set<string> ans;

        for (auto &x : a) {
            for (auto &y : b) {
                ans.insert(x + y);
            }
        }

        return ans;
    }

    set<string> solve(string &s, int &i) {

        set<string> ans;
        set<string> curr;

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union
                for (auto &x : curr)
                    ans.insert(x);

                curr.clear();
                i++;
            }

            else if (s[i] == '{') {
                i++; // skip '{'

                set<string> temp = solve(s, i);

                i++; // skip '}'

                if (curr.empty()) {
                    curr = temp;
                }
                else {
                    curr = combine(curr, temp);
                }
            }

            else {
                // lowercase letter
                string ch(1, s[i]);
                i++;

                set<string> temp = {ch};

                if (curr.empty()) {
                    curr = temp;
                }
                else {
                    curr = combine(curr, temp);
                }
            }
        }

        // Add the last expression after comma
        for (auto &x : curr)
            ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = solve(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};