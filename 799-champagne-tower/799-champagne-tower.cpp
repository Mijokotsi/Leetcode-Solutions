class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        // defining a vector matrix that will hold our glasses
        vector<vector<double>> dp(101, vector<double> (101, 0));
        
        // All glasses are poured at once on the first glass hence 
        // dp[0][0] = poured
        dp[0][0] = poured;
        
        // Running the loop for traversing all the glasses
        for(int i = 0; i < 100; i++)
            for(int j = 0; j <= i; j++)
                
                // If there's an overflow
                if(dp[i][j] > 1) {
                    
                    // calculate the remaining and add it equally to 
                    // its children (left and right)
                    double remaining = (dp[i][j] - 1);
                    dp[i + 1][j] += remaining/2;
                    dp[i + 1][j + 1] += remaining / 2;
                    
                    // And set its value to 1 as its fully filled now
                    dp[i][j] = 1;
                }

        // Finally return the amaount filled in the glass you require
        return dp[query_row][query_glass];
    }
};