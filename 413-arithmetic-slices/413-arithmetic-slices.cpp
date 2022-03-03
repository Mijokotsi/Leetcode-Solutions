class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        // base cases
        if(A.size() < 3)
        return 0;
    
    int ans = 0;
    for(int i = 0; i < A.size()-1; i++)
    {
        int diff = A[i+1] - A[i];
        
        for(int j = i+2; j < A.size(); j++)
        {
            if(A[j] - A[j-1] == diff)
            {
                ans++;
            }
            else 
            {
                break;
            }
        }
    }
    return ans;
    }
};