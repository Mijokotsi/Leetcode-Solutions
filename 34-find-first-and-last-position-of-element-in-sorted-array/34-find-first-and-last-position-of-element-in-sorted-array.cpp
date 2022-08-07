class Solution {
public:
    
    // function to search last and first occurence of the target element
    int search(vector<int> arr, int target, bool isStartIndex) {
        
        // initialising the nas variable
        int ans = -1;
        int s = 0, e = arr.size()-1;
        
        // Simple bianry search
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(target > arr[mid])
                s = mid+1;
            else if(target < arr[mid])
                e = mid-1;
            else {
                // Else if the target is found, check whether we need to search for
                // frst occurence or the last occurence
                ans = mid;
                // If we want the first occurence, reduce the space search to left 
                // subarray
                if(isStartIndex) {
                    e = mid-1;
                } 
                // Else if we want the last occurence, reduce the space search to
                // right subarray
                else {
                    s = mid+1;
                }
            }
        }
        // return the index stored whether for first or for last occurence
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // ans vector initialized with -1,-1
        vector<int> ans(2, -1);
        
        // Storing the first and last occurence of the element respectively
        int start = search(nums, target, true);
        int last = search(nums, target, false);
        
        ans[0] = start;
        ans[1] = last;
        
        return ans;
    }
};