class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int cnt = INT_MAX;
        int n = arr.size();
        vector<int>best(n,INT_MAX);
        int left =0;
        int sum =0;
        for(int right = 0;right<n;right++){
            sum+=arr[right];
            while(sum>target){
                sum-=arr[left];
                left++;
            }
            if(sum==target){
                int len = right-left+1;
                if(left>0 && best[left-1]!=INT_MAX){
                    cnt = min(cnt,len+best[left-1]);
                }
                best[right] = len;
            }
             if(right > 0) {
                best[right] = min(best[right], best[right - 1]);
            }
        }
        if(cnt==INT_MAX) return -1;
        return cnt;
    }
};