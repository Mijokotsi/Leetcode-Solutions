class Solution {
public:
    
    int binary(vector<int> arr, int target, int s, int e) {
        
        while(s <= e) {
        // In this way the mid will never exceed the value of int in cpp
        int mid = s + (e-s)/2;

        if(target < arr[mid]) {
            e = mid-1;
        }
        else if(target > arr[mid]) {
            s = mid+1;
        } 
        else {
            // ans found
            return mid;
        }
    }

    return -1;
    }
    
    int pivot(vector<int> nums) {
        int s = 0;
        int e = nums.size()-1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(mid < e && nums[mid] > nums[mid+1])
                return mid;
            
            else if(mid > s && nums[mid] < nums[mid-1])
                return mid-1;
            
            else if(nums[s] > nums[mid])
                e = mid-1;
            else
                s = mid+1;
        }
        return -1;
    }
    
    int search(vector<int> &nums, int target) {
        
        int s = 0;
        int e = nums.size()-1;
        int piv = pivot(nums);
        
        if(piv == -1)
            return binary(nums, target, s, e);
        
        if(target == nums[piv])
            return piv;
        
        else if(target >= nums[s])
            return binary(nums, target, s, piv-1);
        
        else
            return binary(nums, target, piv+1, e);
    }
};