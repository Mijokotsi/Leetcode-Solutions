class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        string ans = "";
        int prev = -1;
        vector<bool> vis (s.length(), false);
        
        for(int i=0;i<s.length();i++) {
            for(int j=prev+1;j<t.length();j++) {
                if(s[i] == t[j] and vis[i] == false) {
                    ans += s[i];
                    prev = j;
                    vis[i] = true;
                }
                    
            }
        }
        
        return (s.compare(ans) == 0);
    }
};