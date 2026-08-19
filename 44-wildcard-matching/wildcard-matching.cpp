class Solution {
public:

    bool solve(int i, int j, string &p, string &s, vector<vector<int>>& dp)
    {
        // both pattern and string finished
        if(i == 0 && j == 0)
            return true;

        // pattern finished but string remains
        if(i == 0 && j > 0)
            return false;

        // string finished but pattern remains
        if(i > 0 && j == 0)
        {
            for(int k = 1; k <= i; k++)
            {
                if(p[k-1] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        // character match or '?'
        if(p[i-1] == s[j-1] || p[i-1] == '?')
        {
            return dp[i][j] = solve(i-1, j-1, p, s, dp);
        }

        // '*' case
        if(p[i-1] == '*')
        {
            return dp[i][j] =
                solve(i-1, j, p, s, dp) ||   // '*' matches empty
                solve(i, j-1, p, s, dp);     // '*' matches one/more chars
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(n, m, p, s, dp);
    }
};