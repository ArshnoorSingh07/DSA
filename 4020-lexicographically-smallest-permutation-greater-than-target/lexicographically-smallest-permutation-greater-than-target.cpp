class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c - 'a']++;
        }

        string ans;

        for(int i = 0; i < n; i++) {
            int ch = target[i] - 'a';

            if(freq[ch] > 0) {
                ans.push_back(target[i]);
                freq[ch]--;
            }
            else {
                for(int c = ch + 1; c < 26; c++) {
                    if(freq[c] > 0) {
                        ans.push_back('a' + c);
                        freq[c]--;

                        for(int x = 0; x < 26; x++) {
                            while(freq[x] > 0) {
                                ans.push_back('a' + x);
                                freq[x]--;
                            }
                        }

                        return ans;
                    }
                }

                while(i > 0) {
                    i--;

                    char prev = ans.back();
                    ans.pop_back();

                    freq[prev - 'a']++;

                    int curr = target[i] - 'a';

                    for(int c = curr + 1; c < 26; c++) {
                        if(freq[c] > 0) {
                            ans.push_back('a' + c);
                            freq[c]--;

                            for(int x = 0; x < 26; x++) {
                                while(freq[x] > 0) {
                                    ans.push_back('a' + x);
                                    freq[x]--;
                                }
                            }

                            return ans;
                        }
                    }
                }

                return "";
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            char prev = ans.back();
            ans.pop_back();

            freq[prev - 'a']++;

            int curr = target[i] - 'a';

            for(int c = curr + 1; c < 26; c++) {
                if(freq[c] > 0) {
                    ans.push_back('a' + c);
                    freq[c]--;

                    for(int x = 0; x < 26; x++) {
                        while(freq[x] > 0) {
                            ans.push_back('a' + x);
                            freq[x]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};