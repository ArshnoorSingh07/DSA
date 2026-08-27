class Solution {
public:
    bool solve(string s, int ind, int cnt, vector<vector<int>>&dp)
    {
        int n = s.size();
        if(cnt < 0){
            return false;
        }
        if(ind == n){
            return (cnt == 0);
        }
        if(dp[ind][cnt] != -1){
            return dp[ind][cnt];
        }
        if(s[ind] == '('){
            return dp[ind][cnt] =  solve(s, ind+1, cnt+1, dp);
        }
        if(s[ind] == ')'){
            return dp[ind][cnt] =  solve(s, ind+1, cnt-1, dp);
        }
        return dp[ind][cnt] = solve(s, ind+1, cnt+1,dp) 
            || solve(s, ind+1, cnt-1, dp) 
            || solve(s, ind+1, cnt, dp);
    }

    bool checkValidString(string s) {
        int n = s.size();
        int min = 0;
        int max = 0;
        for(int i = 0; i<n;i++)
        {
            if(s[i] =='('){
                min++;
                max++;
            }
            else if(s[i] ==')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min < 0){
                min = 0;
            }
            if(max < 0){
                return false;
            }
        }

        return (min == 0);
        
    }
};