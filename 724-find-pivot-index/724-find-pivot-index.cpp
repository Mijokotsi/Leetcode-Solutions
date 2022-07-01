class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
         int sum = 0;
         int Lsum = 0;
         
         // Calculating the entire sum
         for(auto x:nums) {
            sum+=x;
         }
        
         // Now, checking at each step whether the Rsum == Lsum
        // By subtracting the current element we calculate Rsum
        // And if Rsum != Lsum, we add the element to Lsum
         for(int i = 0;i<nums.size();i++) {
            sum -= nums[i];
            if(Lsum == sum)
            {
                return i;
            }
            Lsum+=nums[i];
        }
        return -1;
    }
};