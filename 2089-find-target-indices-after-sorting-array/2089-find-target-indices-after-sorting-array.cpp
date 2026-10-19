class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
       vector<int>ans;
       int smaller = 0;
       int equal = 0;
       int n = nums.size();
       for(int i = 0;i<n;i++){
        if(nums[i]<target){
            smaller++;
        }
        else if(nums[i]==target){
            equal++;
        }
       }
       for(int i = smaller;i<smaller+equal;i++){
        ans.push_back(i);
       }
       return ans;

    }
};