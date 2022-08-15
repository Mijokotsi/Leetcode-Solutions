class Solution {
public:
    // Following is the approach we're following to search target in the rotated array
    // 1. Find the pivot element: The largest element
    // 2. Search for the target in the arrays left and right to the pivot
    
    // Simple function to perform binary search
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
    
    // Function to find the pivot element
    int pivot(vector<int> nums) {
        int s = 0;
        int e = nums.size()-1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            // When the mid element is greater than the mid+1 element, we've found the pivot
            // element, and in order to avoid the pointer going outside the index range, put a 
            // check that mid should be less than the last index as we're going to check in 
            // forward direction
            if(mid < e && nums[mid] > nums[mid+1])
                return mid;
            
            // When the mid element is less than the  mid-1 element, we've again found the pivot
            // element, and in order to avoid the pointer going outside the index range, put a 
            // check that mid should be greater than the first index as we're going to check in 
            // backward direction
            else if(mid > s && nums[mid] < nums[mid-1])
                return mid-1;
            
            // Now if the start element is greater than the mid element, then it means that the 
            // pivot lies in the array left of the mid element
            else if(nums[s] > nums[mid])
                e = mid-1;
            
            //Else it would lie in the right array, if the start element is smaller than the mid
            // element
            else
                s = mid+1;
        }
        return -1;
    }
    
    // Function to search the target element in the rotated array
    int search(vector<int> &nums, int target) {
        
        int s = 0;
        int e = nums.size()-1;
        
        // Storing the index of the pivot element
        int piv = pivot(nums);
        
        // If pivot is not found, this means our array is not rotated, hence perform simple
        // binary search
        if(piv == -1)
            return binary(nums, target, s, e);
        
        // If the target == pivot element, then simply return the pivot element index
        if(target == nums[piv])
            return piv;
        
        // If the start element is smaller or equal to the target element, then it means the 
        // target lies in the left array of the pivot element, as that array is sorted in
        // ascending order, hence perform binary search
        else if(target >= nums[s])
            return binary(nums, target, s, piv-1);
        
        // Else, the target will simply lie in the other side (right) array, as start element
        // would be greater than the target element
        else
            return binary(nums, target, piv+1, e);
    }
};