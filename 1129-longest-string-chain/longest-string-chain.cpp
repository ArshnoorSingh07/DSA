class Solution {
public:

    bool checkPossible(string &s1, string &s2){
        if(s1.size() != s2.size() + 1) return false;
        int first = 0;
        int second = 0;
        while(first < s1.size())
        {
            if(second < s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()){
            return true;
        }
        else return false;
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(),
            [](string &s1, string &s2) {
                return s1.size() < s2.size();
            });
            
        int n = words.size();
        int maxi = 1;
        vector<int>dp(n,1);
        for(int i = 1; i<n; i++){
            for(int j = 0; j< i; j++)
            {
                if(checkPossible(words[i], words[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};