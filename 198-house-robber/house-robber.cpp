class Solution {
public:
    int solve(vector<int> a, int n, vector<int>&dp){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = max(solve(a,n-2,dp)+a[n-1],solve(a,n-1,dp));
    }
    int rob(vector<int>& a) {
        int n=a.size();
        vector<int>dp(n+1,-1);
        int r=solve(a,n,dp);
        return r;
    }
};