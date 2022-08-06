class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        // declaring the variables
        int s = 0, e = nums.size()-1;
        int ans = 0;
        
        // looping and following the same procedure of binary search
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(target > nums[mid])
                s = mid+1;
            
            else if(target < nums[mid])
                e = mid-1;
            
            else
                return mid;
        }
        
        // if the element is not found, return e+1, i.e., 
        // index just greater than the last index
        return e+1;
    }
};