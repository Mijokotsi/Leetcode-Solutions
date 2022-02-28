class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Srting both the strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Checking id both the strings are equal or not
        if(s.compare(t) == 0)
            return true;
        else
            return false;
    }
};
