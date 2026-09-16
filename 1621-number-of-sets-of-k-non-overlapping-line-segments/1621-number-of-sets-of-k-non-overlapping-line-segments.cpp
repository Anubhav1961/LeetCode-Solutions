class Solution {
public:
    long long mod = 1e9+7;
    unordered_map<string,long long>mp;
    long long solve(int n,int r){
        if(r==0 || r==n){
            return 1;
        }
        string key = to_string(n) + "," + to_string(r);

        if (mp.find(key) != mp.end())
            return mp[key];

        return mp[key] = (solve(n - 1, r - 1) + solve(n - 1, r)) % mod;
    }
    int numberOfSets(int n, int k) {
       return solve(n + k - 1, 2 * k);

    }
};