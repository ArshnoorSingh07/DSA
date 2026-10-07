class Solution {
public:
    bool valid(string s) {
        int balance = 0;

        for(char ch : s) {
            if(ch == '(')
                balance++;
            else if(ch == ')')
                balance--;

            if(balance < 0)
                return false;
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        unordered_set<string> visited;
        vector<string> ans;

        q.push(s);
        visited.insert(s);

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                string curr = q.front();
                q.pop();

                if(valid(curr)) {
                    ans.push_back(curr);
                    continue;
                }

                if(!ans.empty())
                    continue;

                for(int i = 0; i < curr.size(); i++) {
                    if(curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) + curr.substr(i + 1);

                    if(!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            if(!ans.empty())
                return ans;
        }

        return {""};
    }
};