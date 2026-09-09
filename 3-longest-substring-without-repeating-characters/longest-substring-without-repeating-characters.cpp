class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int n = s.size();
        vector<int>hash(256,0);
        int maxLen = 0;
        while(r < n)
        {
            hash[s[r]]++;
            while(hash[s[r]] > 1){
                hash[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};