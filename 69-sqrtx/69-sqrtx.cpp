class Solution {
public:
    int mySqrt(int x) {
        
        int s = 0;
        int e = x/2;
        long long int ans = -1;    // To hold the value of the square root
        
        // Base case
        if(x == 1 || x == 0)
            return x;
        
        while(s <= e) {
            
            long long int mid = s + (e-s)/2;
            long long int sq = mid*mid;
            
            // So, if the square is less than the number given, then we need to move ahead
            // i.e. to a bigger value
            // else if it is greater, then we need to move towards lower value
            if(sq == x)
                return mid;
            else if(sq > x)
                e = mid-1;
            
            // Before moving ahead, store the previous value in ans variable
            else {
                ans = mid;
                s = mid+1;
            }
        }
        return ans;
    }
};