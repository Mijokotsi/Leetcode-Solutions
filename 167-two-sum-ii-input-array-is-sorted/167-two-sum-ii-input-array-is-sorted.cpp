class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int target) {
        
        
        int start = 0;
        int end = ar.size()-1;
        vector<int> ans;
        
        while(start <= end) {
            
            if(ar[start] + ar[end] > target)
                end--;
            
            else if(ar[start] + ar[end] < target)
                start++;
            
            else {
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
        }
        
        return ans;
    }
};