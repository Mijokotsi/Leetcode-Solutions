class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        // declaring the variables
        int s = 0, e = nums.size()-1;
        int ans = 0;
        
        // edge case: if the target is greater than the last element
        // as the array is sorted, so there just return position next to last index
        
        // if(target > nums[e])
        //     return e+1;
        
        // looping and following the same procedure of binary search
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(target > nums[mid]) {
                // incrementing s and at the same time, storing the index
                s = mid+1;
                // ans = s;
            }
            else if(target < nums[mid])
                e = mid-1;
            
            else
                return mid;
        }
        
        // returning the answer
        return e+1;
    }
};