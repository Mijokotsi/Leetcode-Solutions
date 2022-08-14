class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int start = 0;
        int end = arr.size()-1;
        
        while(start <= end) {
            
            int mid = start + (end-start)/2;
            
            if(arr[mid+1] < arr[mid] and arr[mid-1] < arr[mid])
                return mid;
            
            else if(arr[mid+1] < arr[mid])
                end = mid-1;
            else
                start = mid+1;
        }
        
        return -1;
    }
};