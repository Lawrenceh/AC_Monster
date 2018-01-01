/* dfs: 1) check if current prefix is valid 2) if not, dfs on each character with LAST POSITION maintained 3) only go to the next step if the remaining is character valid 4) do same on reverse and the other character 5) if both these are good, write it down */
class Solution {
private:
    vector<string> ans;
public:
    void dfs(string s, char ch, int last) {  
        int cnt = 0;
        for (int i = 0; i < s.size(); i ++) {  
            if (s[i] == '(' || s[i] == ')') s[i] == ch ? cnt ++ : cnt --;  
            if (cnt <= 0) continue;
            // "remove" character step
            for (int j = last; j <= i; j ++) { // remove each "ch" from last position and do dfs for following steps
                if (s[j] == ch && (j == last || s[j - 1] != ch)) { // pruning: skip those consecutive ones
                    dfs(s.substr(0, j) + s.substr(j + 1), ch, j); // using last because, if we remove some later ch, and start a new search, there could be duplicating results as we might remove some ch prior to this and yield same next step string
                }
            }
            return;
        }
        // any s which comes to this point satisfies that, it is valid based on "ch"='(' judgement
        reverse(s.begin(), s.end());  
        if (ch == ')') return dfs(s, '(', 0); // now check the reverse based on ')'
        ans.push_back(s); // if both are good, add it to the result
    }
    vector<string> removeInvalidParentheses(string s) {  
        dfs(s, ')', 0);
        return ans;
    }
};  
