class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;

        for(auto &it : knowledge) {
            mpp[it[0]] = it[1];
        }

        string ans = "";
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                string key = "";
                i++;

                while(s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if(mpp.find(key) != mpp.end())
                    ans += mpp[key];
                else
                    ans += "?";
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};