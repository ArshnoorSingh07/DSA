class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp) + solve(i-1, j, s1, s2,dp); 
        }
        else{
            return dp[i][j] = solve(i-1,j, s1, s2,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1, vector<int>(m + 1,-1));
        return solve(n,m,s,t,dp);
    }
};