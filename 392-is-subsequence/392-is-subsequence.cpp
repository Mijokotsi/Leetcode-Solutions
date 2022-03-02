class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        // To hold the string which we extract out after comparing s with t
        string ans = ""; 
        
        // variable to hold the index of the previous element checked
        // so that we can start to check elements ahead of it from next iteration
        int prev = -1;
        
        // vector to check is the element already visited or not
        // false = not visited
        // true = visited
        vector<bool> vis (s.length(), false);
        
        // Loop for checking with TC: O(n^2)
        for(int i=0;i<s.length();i++) {
            for(int j=prev+1;j<t.length();j++) {
                
                // If the elements are equal and not visited yet
                if(s[i] == t[j] and vis[i] == false) {
                    ans += s[i];   // append it to ans string
                    prev = j;      // Setting new j with this element's index
                    vis[i] = true;  // marking it as visited
                }
                    
            }
        }
        
        // comapring the extracted string with the subsequence
        return (s.compare(ans) == 0);
    }
};