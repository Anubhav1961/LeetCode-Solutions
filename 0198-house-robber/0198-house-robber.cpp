class Solution {
public:
    int f(int ind,vector<int>&nums,vector<int>&dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind]+f(ind-2,nums,dp);
        int nonPick = f(ind-1,nums,dp);
        return dp[ind] = max(pick,nonPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n+1,-1);
        // return f(n-1,nums,dp);


        ///Tabulation
        vector<int>dp(n+1,-1);
        dp[0] = nums[0];
        int neg = 0;
        for(int i = 1;i<n;i++){
            int take = nums[i];
            if(i>1){
                take += dp[i-2];
            }
            int ntake = dp[i-1];
            dp[i] = max(take,ntake);
        }
        return dp[n-1];
        
    }
};