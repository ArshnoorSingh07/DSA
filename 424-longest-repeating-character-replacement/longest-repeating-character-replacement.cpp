class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mpp;
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;
        int maxFreq = 0;
        while(r<n)
        {
            mpp[s[r] - 'A']++;
            maxFreq = max(maxFreq, mpp[s[r]-'A']);

            if((r-l+1) - maxFreq > k){
                mpp[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};