class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        long long odd = 0;
        long long even = 1;
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum += arr[i];
            if(sum%2==0) even++;
            else odd++;
        }
        return (even*odd) % mod;
    }
};