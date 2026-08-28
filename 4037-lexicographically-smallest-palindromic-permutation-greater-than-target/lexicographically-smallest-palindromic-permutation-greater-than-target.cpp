class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for(char ch : s) {
            cnt[ch - 'a']++;
        }

        int odd = 0;
        char middle = '\0';

        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2) {
                odd++;
                middle = 'a' + i;
            }
        }

        if(odd > 1) return "";

        vector<int> half(26);

        for(int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int len = n / 2;
        string left = "";

        auto possible = [&]() {
            string temp = left;

            for(int i = 25; i >= 0; i--) {
                temp += string(half[i], 'a' + i);
            }

            string palindrome = temp;

            if(n % 2)
                palindrome += middle;

            string rev = temp;
            reverse(rev.begin(), rev.end());

            palindrome += rev;

            return palindrome > target;
        };

        for(int pos = 0; pos < len; pos++) {
            bool found = false;

            for(int ch = 0; ch < 26; ch++) {
                if(half[ch] == 0)
                    continue;

                left.push_back('a' + ch);
                half[ch]--;

                if(possible()) {
                    found = true;
                    break;
                }

                half[ch]++;
                left.pop_back();
            }

            if(!found)
                return "";
        }

        string ans = left;

        if(n % 2)
            ans += middle;

        string right = left;
        reverse(right.begin(), right.end());

        ans += right;

        return ans > target ? ans : "";
    }
};