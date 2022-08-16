class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int target) {
        
        
        int start = 0;
        int end = ar.size()-1;
        int sum = 0;
        vector<int> ans;     // vector to store the array
        
        // Loop will end as soon as we get our pair
        while(start <= end) {
            sum = ar[start] + ar[end];
            // Check if the sum of start and emd element is greater than the target
            // then move end pointer back, as now we need to reduce the sum in order to match
            // with the target
            if(sum > target)
                end--;
            
            // Check if the sum of start and emd element is smaller than the target
            // then move start pointer ahead, as now we need to increase the sum in order to
            // match with the target
            else if(sum < target)
                start++;
            
            // Else we've found the match, hence push the index to the answer array in
            // increasing order
            else {
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
        }
        
        return ans;
    }
};