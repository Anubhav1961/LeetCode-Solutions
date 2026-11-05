class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        int smallest = INT_MIN;
        int largest = 1;//for length
        int cnt = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(nums[i]-1==smallest){
                cnt++;
                smallest = nums[i];
            }
            else if(nums[i]!=smallest){
                cnt = 1;
                smallest = nums[i];
            }
            largest = max(largest,cnt);
        }
        return largest;;
        
    }
};