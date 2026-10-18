class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0;i<n;i++){
            int m = target-nums[i];
            if(mp.count(m)){
                return {i,mp[m]};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};