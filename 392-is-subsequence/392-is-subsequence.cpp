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


// Alternate Solution in TC: O(n)

#define ll int
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        // Setting indexes for both the strings
        ll spos=0, tpos=0;
        
        // Running loop till the end of the string t is reached
        while(tpos<t.size()){
            
            // If elements match increment the index of string s
            if(s[spos]==t[tpos])spos++;
            
            // else increment the index of string t
            tpos++;
        }
        
        // If the elements would be present order wise in the string t
        // we'll reach the end of string s, and answer would be true, else false
        return (spos==s.size());
    }
};
