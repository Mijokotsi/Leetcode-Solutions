class Solution {
public:
    int mySqrt(int x) {
        
        int s = 0;
        int e = x/2;
        long long int ans = -1;
        
        if(x == 1 || x == 0)
            return x;
        
        while(s <= e) {
            
            long long int mid = s + (e-s)/2;
            long long int sq = mid*mid;
            
            if(sq == x)
                return mid;
            else if(sq > x)
                e = mid-1;
            else {
                ans = mid;
                s = mid+1;
            }
        }
        return ans;
    }
};