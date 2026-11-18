class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
        // vector<int> ans;
        // unordered_map<int, int> mp;
        // for (int i = 0; i < nums.size(); i++) {
        //     mp[nums[i]]++;
        // }
        // vector<pair<int, int>> v(mp.begin(), mp.end());

        // sort(v.begin(), v.end(), [](auto& a, auto& b) {
        //     return a.second > b.second;
        // });

        // for (int i = 0; i < k; i++) {
        //     ans.push_back(v[i].first); 
        // }
        // return ans;
    // }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};