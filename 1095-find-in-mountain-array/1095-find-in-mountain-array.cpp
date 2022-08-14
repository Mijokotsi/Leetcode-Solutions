/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int binary(MountainArray &mountainArr, int s, int e, int target) {
        
        // Check if the array is sorted in asceding or descending order
    bool isAsc = mountainArr.get(s) < mountainArr.get(e);

    while(s <= e) {
        // In this way the mid will never exceed the value of int in cpp
        int mid = s + (e-s)/2;

        if(target == mountainArr.get(mid)) 
            return mid;

        if(isAsc) {
            if(target < mountainArr.get(mid)) {
                e = mid-1;
            }
            else {
                s = mid+1;
            } 
        }
        else {
            if(target > mountainArr.get(mid)) {
                e = mid-1;
            }
            else {
                s = mid+1;
            } 
        }
    }

    return -1;
    }
    
    int peakElement(MountainArray &mountainArr) {
        
        int start = 0;
        int end = mountainArr.length()-1;
        
        // The loop is going to break when only a single element will be remaining in the array
        // as both start and end will be pointing to the same element
        while(start < end) {
            
            // pointing mid
            int mid = start + (end-start)/2;
            
            // if the next element of middle is smaller than the middle one, then the search
            // space is in the left side (decreasing array)
            if(mountainArr.get(mid+1) < mountainArr.get(mid))
                // As this middle could also be a possible answer hence end != mid-1 
                // instead we'll include this number in our next search space
                end = mid;
            else
                // If the next element is greater than the middle element, we know that the
                // new seach space will be on the right side
                // And since this number is smaller than the next element, we'll not include
                // this element in the array
                start = mid+1;
        }
        // At the end, just return start or end, as both will be pointing to the same element
        return start;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = peakElement(mountainArr);
        
        int left = binary(mountainArr, 0, peak, target);
        if(left != -1)
            return left;
        else
            return binary(mountainArr, peak+1, mountainArr.length() -1, target);
       
    }
    
};