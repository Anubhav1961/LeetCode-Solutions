// class Solution {
// public:
//     vector<string> maxNumOfSubstrings(string s) {
        
//         unordered_map<char, pair<int, int>> mp;
//         // first and last occurrence ko store kara
//         for (int i = 0; i < s.size(); i++) {
//             char ch = s[i];

//             if (mp.find(ch) == mp.end()) {
//                 mp[ch] = {i, i};
//             } 
//             else {
//                 mp[ch].second = i;
//             }
//         }

//         vector<pair<int, int>> intervals;

//         // Create valid intervals
//         for (auto it : mp) {

//             char ch = it.first;

//             int l = it.second.first;
//             int r = it.second.second;

//             bool valid = true;

//             for (int i = l; i <= r; i++) {

//                 char x = s[i];

//                 // x ka koi occurrence l se pehle hai
//                 if (mp[x].first < l) {
//                     valid = false;
//                     break;
//                 }

//                 // interval ko expand karo
//                 r = max(r, mp[x].second);
//             }

//             if (valid) {
//                 intervals.push_back({l, r});
//             }
//         }

//         // End position ke according sort
//         sort(intervals.begin(), intervals.end(),
//              [](pair<int,int> a, pair<int,int> b) {
//                  return a.second < b.second;
//              });

//         vector<string> ans;

//         int prevEnd = -1;

//         // Greedy
//         for (auto p : intervals) {

//             int l = p.first;
//             int r = p.second;

//             if (l > prevEnd) {
//                 ans.push_back(s.substr(l, r - l + 1));
//                 prevEnd = r;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // First and last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Create valid intervals
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';

                if (first[x] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        // Greedy
        for (auto &[l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};