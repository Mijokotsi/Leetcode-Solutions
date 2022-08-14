class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start = 0;
        int end = arr.size()-1;
        
        // The loop is going to break when only a single element will be remaining in the array
        // as both start and end will be pointing to the same element
        while(start < end) {
            
            // pointing mid
            int mid = start + (end-start)/2;
            
            // if the next element of middle is smaller than the middle one, then the search
            // space is in the left side (decreasing array)
            if(arr[mid+1] < arr[mid])
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
        
        return start;
    }
};