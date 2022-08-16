class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int start = 1;
        int end = num/2;
        
        if(num == 1)
            return true;
        
        while(start <= end) {
            
            long long mid = start + (end - start)/2;
            
            double check = mid*mid;
            if(check > num)
                end = mid-1;
            
            else if(check < num)
                start = mid+1;
            
            else
                return true;
        }
        
        return false;
    }
};