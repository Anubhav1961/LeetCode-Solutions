class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        // vector<int>ans;
        // for(int i = 0;i<n;i++){
        //     int m = nums[i];
        //     int mx = m;
        //     for(int j = i+1;j<n;j++){
        //         if(mx<nums[j]){
        //             mx = nums[j];
        //         }
        //     }
        //     ans.push_back(mx-m);
        // }
        // return *max_element(ans.begin(),ans.end());

        int profit = 0;
        int mini = nums[0];
        for(int i = 1;i<n;i++){
            profit = max(profit,nums[i]-mini);
            mini = min(nums[i],mini);
        }
        return profit;
    }
};