class Solution {
public:
    string s;
    int i = 0;

    set<string> solve() {
        set<string> res;
        set<string> curr = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                res.insert(curr.begin(), curr.end());
                curr = {""};
                i++;
            }
            else {
                set<string> next;

                if (s[i] == '{') {
                    i++;
                    next = solve();
                    i++;
                }
                else {
                    next.insert(string(1, s[i]));
                    i++;
                }

                set<string> temp;

                for (auto &a : curr) {
                    for (auto &b : next) {
                        temp.insert(a + b);
                    }
                }

                curr = temp;
            }
        }

        res.insert(curr.begin(), curr.end());

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;

        set<string> ans = solve();

        return vector<string>(ans.begin(), ans.end());
    }
};