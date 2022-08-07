class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        int s = 0, e = arr.size() - 1;
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
};